#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

class Logger {
private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    static Logger& getInstance();

    void log(const std::string& mesaj);
};


#endif //LOGGER_H
