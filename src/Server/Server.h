/**
 * @file
 * @date 2024/08/22
 * @brief ファイルの説明
 * @details ファイルの詳細
 * @author saku shirakura (saku@sakushira.com)
 */


#ifndef ECHO_SERVER_SERVER_H
#define ECHO_SERVER_SERVER_H


class Server {
public:
    Server() = default;

    [[noreturn]] static void serve(int port);

};


#endif //ECHO_SERVER_SERVER_H
