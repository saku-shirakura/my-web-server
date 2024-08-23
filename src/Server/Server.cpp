#include <cstring>
#include <unistd.h>
#include "Server.h"
#include "Socket.h"

[[noreturn]] void Server::serve(int port) {
    Socket sock(port);
    sock.listen();
    while (true) {
        std::cout << sock.accept() << std::endl;
        char xx[] = "HTTP/1.1 404 Not Found.\r\nserver: sa9ra\r\nconnection: close\r\n\r\n";
        write(sock.getAcceptedSocket(), &xx, 61);
    }
}
