#pragma once

#include <algorithm>
#include <arpa/inet.h>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <iostream>
#include <memory>
#include <netdb.h>
#include <netinet/in.h>
#include <poll.h>
#include <string>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

#define DEFAULT_PORT 8080
#define DEFAULT_ACTIVITY_TIMEOUT_MS 5000
#define BACKLOG_SIZE 10
#define MAX_BUFFER_SIZE 4096

class SocketHandler {
public:
  SocketHandler(int port = DEFAULT_PORT);
  SocketHandler(int sockfd, sockaddr_in addr);
  SocketHandler(uint32_t addr_flag, int port = DEFAULT_PORT);
  SocketHandler(const std::string &addr, int port = DEFAULT_PORT);
  virtual ~SocketHandler() = default;

  virtual void run() = 0;

  inline void set_name(const std::string &name) { _name = name; }
  inline const std::string &get_name() const { return _name; }

  inline void set_addr(const sockaddr_in &addr) { _addr = addr; }
  inline const sockaddr_in &get_addr() const { return _addr; }

  inline void set_sockfd(int sockfd) { _sockfd = sockfd; }
  inline int get_sockfd() const { return _sockfd; }

protected:
  int _sockfd;
  sockaddr_in _addr;
  socklen_t _addr_len;
  std::string _name;
  char _buffer[MAX_BUFFER_SIZE];

  void handle_error(const char *fmt...);
  int send_message(const char *fmt...);
  int read_message();

  inline void reset_buffer() { memset(_buffer, '\0', MAX_BUFFER_SIZE); }
};
