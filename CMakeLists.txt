cmake_minimum_required(VERSION 3.28)
project(my_web_server)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_web_server src/main.cpp
        src/Server/Socket.cpp
        src/Server/Socket.h
        src/Server/Server.cpp
        src/Server/Server.h)
