#ifndef EXCEPTIENIVELEXPERIENTA_H
#define EXCEPTIENIVELEXPERIENTA_H

#include <exception>

class ExceptieNivelExperienta : public std::exception {
public:
    const char* what() const noexcept override {
        return "Nivelul de experienta al antrenorului este invalid!";
    }
};

#endif // EXCEPTIENIVELEXPERIENTA_H
