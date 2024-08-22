#include <cstring>
#include <unistd.h>
#include "Server.h"
#include "Socket.h"

[[noreturn]] void Server::serve(int port) {
    Socket sock(port);
    sock.listen();
    while (true) {
        std::cout << sock.accept() << std::endl;
    }
}
