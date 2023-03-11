#include "server.hpp"
#include "client.hpp"

Server::Server(int port) : SocketHandler(port) {}

Server::Server(int sockfd, sockaddr_in addr) : SocketHandler(sockfd, addr) {}

Server::Server(uint32_t addr_flag, int port) : SocketHandler(addr_flag, port) {}

Server::Server(const std::string &addr, int port) : SocketHandler(addr, port) {}

void Server::run() {
  if (_sockfd == -1)
    handle_error("Invalid socket, please check the creation of the socket: %d.",
                 _sockfd);

  if (bind(_sockfd, (sockaddr *)&_addr, _addr_len) == -1)
    handle_error("Could not bind the server socket to the port: %d.\nPlease "
                 "check that this port is available.",
                 _addr.sin_port);

  if (listen(_sockfd, _backlog_size) == -1)
    handle_error("Could not listen to the server socket.");

  std::cout << "Server running on port: " << _addr.sin_port
            << "\nWaiting for connections..." << std::endl;

  _fds[0].fd = _sockfd;
  _fds->events = POLLIN;

  while (true) {
    int activity = poll(_fds, _clients.size() + 1, _activity_timeout_sec);

    if (activity > 0) {
      if (_fds[0].revents & POLLIN) {
        accept_connection();
      }

      for (int i = 0; i < BACKLOG_SIZE; ++i) {
        if (_fds[i].revents & POLLIN && _fds[i].fd != _sockfd) {
          // socket ready to be read from
          int bytes_read = read_message_from(_fds[i].fd);
          if (bytes_read == -1)
            handle_error("Could not read the message from the socket: %d.",
                         _fds[i].fd);

          std::cout << _fds[i].fd << ": " << _buffer << std::endl;
          _fds[i].events = POLLOUT;
        }
        if (_fds[i].revents & POLLOUT) {
          // socket ready to be written to
          send_message_to(_fds[i].fd, "Message received successfully\0");
          _fds[i].events = POLLIN;
        }
        if (_fds[i].revents & (POLLHUP | POLLERR)) {

          int sockfd_to_remove = _fds[i].fd;
          std::cout << "Client (" << sockfd_to_remove << ") has disconnected !"
                    << std::endl;

          auto it = std::find_if(
              _clients.begin(), _clients.end(),
              [sockfd_to_remove](const std::unique_ptr<SocketHandler> &client) {
                return client->get_sockfd() == sockfd_to_remove;
              });

          if (it != _clients.end())
            _clients.erase(it);

          close(_fds[i].fd);
          _fds[i].fd = -1;
          _fds[i].events = 0;
          _fds[i].revents = 0;
        }
      }
    } else if (activity == 0) {
      std::cout << "No activity detected in the last "
                << DEFAULT_ACTIVITY_TIMEOUT_MS / 1000 << " seconds."
                << std::endl;
    } else {
      handle_error("poll error.");
    }
  }
}

void Server::accept_connection() {
  int client_sockfd;
  sockaddr_in client_addr;
  socklen_t client_addr_len;

  client_sockfd = accept(_sockfd, (sockaddr *)&client_addr, &client_addr_len);
  if (client_sockfd == -1)
    handle_error("Could not accept connection from the client.");

  reset_buffer();

  if (inet_ntop(AF_INET, &client_addr.sin_addr, _buffer, INET_ADDRSTRLEN) ==
      NULL)
    handle_error("inet_ntop error: Could not parse the client ip address.");

  std::cout << "New connection from " << _buffer << ":" << client_addr.sin_port
            << "." << std::endl;

  Client new_client(client_sockfd, client_addr);
  _clients.push_back(std::make_unique<Client>(new_client));

  _fds[_clients.size()].fd = new_client.get_sockfd();
  _fds[_clients.size()].events = POLLIN | POLLOUT;
}

int Server::read_message_from(int sockfd) {
  reset_buffer();

  int bytes_read = read(sockfd, _buffer, MAX_BUFFER_SIZE);

  return bytes_read;
}

int Server::send_message_to(int sockfd, const char *fmt...) {
  va_list ap;
  va_start(ap, fmt);

  vsnprintf(_buffer, MAX_BUFFER_SIZE, fmt, ap);

  size_t message_len = strlen(_buffer);

  if (message_len && _buffer[message_len - 1] == '\n')
    _buffer[message_len - 1] = '\0';

  int bytes_sent = write(sockfd, _buffer, message_len);

  reset_buffer();

  va_end(ap);
  return bytes_sent;
}
