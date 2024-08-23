/**
 * @file
 * @date 2024/08/23
 * @brief ファイルの説明
 * @details ファイルの詳細
 * @author saku shirakura (saku@sakushira.com)
 */


#ifndef MY_WEB_SERVER_LOGGER_H
#define MY_WEB_SERVER_LOGGER_H

#include <iostream>
#include <ctime>
#include <chrono>

class Logger {
public:

    enum class Level {
        NOTE = 0,
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    static std::string levelToString(Level lv);

    [[maybe_unused]] static void log(Level lv, const std::string &msg);
};

#endif //MY_WEB_SERVER_LOGGER_H
