#include "Logger.h"

Logger& Logger::getInstance() {
    static Logger instanta;
    return instanta;
}

void Logger::log(const std::string& mesaj) {
    std::cout << "[LOG] " << mesaj << "\n";
}

