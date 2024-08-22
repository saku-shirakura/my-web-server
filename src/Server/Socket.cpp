#include <cstring>
#include <unistd.h>
#include "Socket.h"
#include <regex>
#include "sys/ioctl.h"

Socket::~Socket() {
    close(_last_response_socket);
    shutdown(_socket, SHUT_RDWR);
}

Socket::Socket(int port) : _sin(sockaddr_in()) {
    _socket = socket(PF_INET, SOCK_STREAM, 0);
    if (_socket == -1) {
        std::cout << "Socket error." << std::endl;
        exit(1);
    }
    bzero(&_sin, sizeof _sin);
    _sin.sin_family = AF_INET;
    _sin.sin_port = htons(port);
    _sin.sin_addr.s_addr = INADDR_ANY;
    if (bind(_socket, (sockaddr *) &_sin, sizeof _sin) == -1) {
        std::cout << "Socket bind error\nerrno: " << errno << std::endl;
        exit(1);
    }
}

int Socket::get_socket() const {
    return _socket;
}

void Socket::listen() const {
    if (::listen(this->get_socket(), 5) == -1) {
        std::cout << "listen error\nerrno: " << errno << std::endl;
        exit(1);
    }
}

std::string Socket::accept() {
    std::string request;
    _last_response_socket = -1;
    _last_response_socket = ::accept(this->get_socket(), nullptr, nullptr);
    if (_last_response_socket == -1) {
        std::cout << "socket error\nerrno: " << errno << std::endl;
    } else {
        char xx[] = "HTTP/1.1 404 Not Found.\r\nserver: sa9ra\r\nconnection: close\r\n\r\n";
        int read_len;
        if (ioctl(_last_response_socket, FIONREAD, &read_len) < 0) {
            std::cout << "read error\nerrno: " << errno << std::endl;
        } else {
            int reaming_len = read_len;
            int buff_size = 256;
            char buff[buff_size];
            while (true) {
                ssize_t tmp_read_len = read(_last_response_socket, &buff, buff_size - 1);
                buff[tmp_read_len] = '\0';
                request.append(buff);
                reaming_len -= static_cast<int>(tmp_read_len);
                if (reaming_len <= 0)
                    break;
            }
            write(_last_response_socket, &xx, 61);
        }
    }
    if (_last_response_socket != -1)
        close(_last_response_socket);
    return request;
}

Socket::Socket() : Socket(3000) {}
