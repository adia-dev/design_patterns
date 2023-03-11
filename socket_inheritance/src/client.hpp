#pragma once

#include "socket_handler.hpp"

class Client : public SocketHandler {
public:
  Client(int port = DEFAULT_PORT);
  Client(int sockfd, sockaddr_in addr);
  Client(uint32_t addr_flag, int port = DEFAULT_PORT);
  Client(const std::string &addr, int port = DEFAULT_PORT);
  ~Client() = default;

  void run() override;

private:
};
