#include "socket_handler.hpp"

SocketHandler::SocketHandler(int port) {
  _addr_len = sizeof(_addr);
  bzero(&_addr, _addr_len);

  _addr.sin_family = AF_INET;
  _addr.sin_port = port;
  _addr.sin_addr.s_addr = INADDR_ANY;

  _sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (_sockfd == -1)
    handle_error("Could not create the socket.");

  int opt = 1;
  if (setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
    handle_error("Could not set the SO_REUSEADDR option to the socket.");
}

SocketHandler::SocketHandler(int sockfd, sockaddr_in addr)
    : _sockfd(sockfd), _addr(addr) {}

SocketHandler::SocketHandler(uint32_t addr_flag, int port) {
  _addr_len = sizeof(_addr);
  bzero(&_addr, _addr_len);

  _addr.sin_family = AF_INET;
  _addr.sin_port = port;
  _addr.sin_addr.s_addr = addr_flag;

  _sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (_sockfd == -1)
    handle_error("Could not create the socket.");
}

SocketHandler::SocketHandler(const std::string &addr, int port) {
  _addr_len = sizeof(_addr);
  bzero(&_addr, _addr_len);

  _addr.sin_family = AF_INET;
  _addr.sin_port = port;

  if (inet_pton(AF_INET, addr.c_str(), &_addr.sin_addr.s_addr) == -1)
    handle_error("Could not parse the INET adress: %s", addr.c_str());

  _sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (_sockfd == -1)
    handle_error("Could not create the socket.");
}

void SocketHandler::handle_error(const char *fmt...) {
  va_list ap;
  va_start(ap, fmt);

  int err_no = errno;

  fprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");

  if (err_no != -1) {
    fprintf(stderr, "(errno = %d): %s\n\n", err_no, strerror(err_no));
  }

  va_end(ap);
  exit(EXIT_FAILURE);
}

int SocketHandler::send_message(const char *fmt...) {
  va_list ap;
  va_start(ap, fmt);

  vsnprintf(_buffer, MAX_BUFFER_SIZE, fmt, ap);

  size_t message_len = strlen(_buffer);
  if (message_len && _buffer[message_len - 1] == '\n')
    _buffer[message_len - 1] = '\0';

  int bytes_sent = write(_sockfd, _buffer, message_len);

  reset_buffer();

  va_end(ap);
  return bytes_sent;
}

int SocketHandler::read_message() {
  reset_buffer();

  int bytes_read = read(_sockfd, _buffer, MAX_BUFFER_SIZE);

  return bytes_read;
}
