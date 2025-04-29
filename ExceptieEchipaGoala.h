#ifndef EXCEPTIEECHIPAGOALA_H
#define EXCEPTIEECHIPAGOALA_H

#include <exception>

class ExceptieEchipaGoala : public std::exception {
public:
    const char* what() const noexcept override {
        return "Echipa nu are niciun antrenor sau jucator!";
    }
};

#endif // EXCEPTIEECHIPAGOALA_H
