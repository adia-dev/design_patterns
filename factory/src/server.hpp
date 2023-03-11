#pragma once

#include "socket_handler.hpp"

class Server : public SocketHandler {
public:
  Server(int port = DEFAULT_PORT);
  Server(int sockfd, sockaddr_in addr);
  Server(uint32_t addr_flag, int port = DEFAULT_PORT);
  Server(const std::string &addr, int port = DEFAULT_PORT);
  ~Server() = default;

  void run() override;

  inline void set_backlog_size(int size) { _backlog_size = size; }
  inline int get_backlog_size() const { return _backlog_size; }

private:
  int _backlog_size = BACKLOG_SIZE;
  pollfd _fds[BACKLOG_SIZE];
  uint16_t _activity_timeout_sec = DEFAULT_ACTIVITY_TIMEOUT_MS;

  std::vector<std::unique_ptr<SocketHandler>> _clients;

  void accept_connection();
  int read_message_from(int sockfd);
  int send_message_to(int sockfd, const char *fmt...);
};
