#include "client.hpp"
#include "server.hpp"

void print_usage() {
  std::cout << "Usage: socket-cli [options]\n"
               "\n"
               "Options:\n"
               "  -h, --help                   Display this help message\n"
               "  -s, --server                 Run as a socket server\n"
               "  -c, --client <name>          Run as a socket client with the "
               "given name\n"
               "  -a, --address <address>      Set the server or client "
               "address (default: 127.0.0.1)\n"
               "  -p, --port <port>            Set the server or client port "
               "(default: 8080)\n";
}

int main(int argc, char *argv[]) {
  int opt;
  bool is_server = false, is_client = false;
  std::string address = "127.0.0.1";
  std::string name = "default";
  int port = DEFAULT_PORT;
  std::unique_ptr<SocketHandler> handler = nullptr;

  while ((opt = getopt(argc, argv, "hsc:a:p:")) != -1) {
    switch (opt) {
    case 'h':
      print_usage();
      return 0;
    case 's':
      is_server = true;
      break;
    case 'c':
      is_client = true;
      if (optind < argc && argv[optind][0] != '-') {
        name = argv[optind++];
      }
      break;
    case 'a':
      address = optarg;
      break;
    case 'p':
      port = atoi(optarg);
      break;
    default:
      print_usage();
      return 1;
    }
  }

  if (!is_server && !is_client) {
    std::cerr << "Error: must specify either -s or -c\n";
    print_usage();
    return 1;
  }

  if (is_server) {
    std::cout << "Running as socket server\n";
    // TODO: implement server code here
    handler = std::make_unique<Server>(port);
  } else if (is_client) {
    std::cout << "Running as socket client\n";
    // TODO: implement client code here
    handler = std::make_unique<Client>(address, port);
    handler->set_name(name);
  }

  std::cout << "Address: " << address << std::endl;
  std::cout << "Port: " << port << std::endl;

  handler->run();

  return 0;
}
