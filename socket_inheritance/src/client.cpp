#include "client.hpp"

Client::Client(int port) : SocketHandler(port) {}

Client::Client(int sockfd, sockaddr_in addr) : SocketHandler(sockfd, addr) {}

Client::Client(uint32_t addr_flag, int port) : SocketHandler(addr_flag, port) {}

Client::Client(const std::string &addr, int port) : SocketHandler(addr, port) {}

void Client::run() {
  if (_sockfd == -1)
    handle_error("Invalid socket, please check the creation of the socket: %d.",
                 _sockfd);

  if (connect(_sockfd, (sockaddr *)&_addr, _addr_len) == -1)
    handle_error("Client (%d) could not connect to the server on port: %d.",
                 _sockfd, _addr.sin_port);

  std::cout << "Successfully connected on server at port: " << _addr.sin_port
            << std::endl;

  int bytes_sent = send_message("%s", _name.c_str());
  int bytes_read = -1;

  while (true) {
    std::cout << "Write a message to the server: ";
    fgets(_buffer, MAX_BUFFER_SIZE, stdin);

    bytes_sent = send_message("%s", _buffer);
    if (bytes_sent == -1)
      handle_error("Client (%d) could not send message to the server.",
                   _sockfd);

    bytes_read = read_message();
    if (bytes_read == -1)
      handle_error("Client (%d) could read the incoming message", _sockfd);

    std::cout << "server: " << _buffer << std::endl;
  }
}
