#include "Logger.h"

std::string levelToString(Level lv) {
    switch (lv) {
        case Level::NOTE:
            return "NOTE";
        case Level::INFO:
            return "INFO";
        case Level::WARNING:
            return "WARNING";
        case Level::ERROR:
            return "ERROR";
        case Level::FATAL:
            return "FATAL";
        default:
            return "UNKNOWN";
    }
}

void logging(Level lv, const std::string &msg) {
    std::chrono::zoned_time zoned_time{std::chrono::system_clock::now()};

    auto s_info = zoned_time.get_info();

    auto lt_form = std::chrono::local_time_format(zoned_time.get_local_time(), &s_info.abbrev);

    std::cout << "[" << levelToString(lv) << "]:" <<
              " " << std::format("{:%F %T %Z}", lt_form) << ":" <<
              " " << msg << std::endl;
}
