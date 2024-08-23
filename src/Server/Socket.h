/**
 * @date 2024/08/22
 * @author saku shirakura (saku@sakushira.com)
 */


#ifndef ECHO_SERVER_SOCKET_H
#define ECHO_SERVER_SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <iostream>

class Socket {
public:
    Socket();

    explicit Socket(int port);

    ~Socket();

    [[nodiscard]] int getSocket() const;

    [[nodiscard]] int getAcceptedSocket() const;

    void listen() const;

    std::string accept();

    void closeAccepted();

private:

    int _socket;
    sockaddr_in _sin;
    int _last_response_socket{};

};

#endif //ECHO_SERVER_SOCKET_H
