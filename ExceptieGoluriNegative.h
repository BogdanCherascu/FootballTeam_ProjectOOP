#ifndef EXCEPTIEGOLURINEGATIVE_H
#define EXCEPTIEGOLURINEGATIVE_H

#include <exception>

class ExceptieGoluriNegative : public std::exception {
public:
    const char* what() const noexcept override {
        return "Numarul de goluri marcate de jucator nu poate fi negativ!";
    }
};

#endif // EXCEPTIEGOLURINEGATIVE_H
