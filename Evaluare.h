#ifndef EVALUARE_H
#define EVALUARE_H

#include "Jucator.h"
#include <iostream>

template <typename T>
class Evaluare {
private:
    Jucator* jucator;
    T scor;

public:
    Evaluare(Jucator* jucator, const T& scor) : jucator(jucator), scor(scor) {}

    void afiseaza() const {
        std::cout << "Evaluare pentru " << jucator->getNume()
                  << " = " << scor << "\n";
    }

    const T& getScor() const { return scor; }
};


#endif //EVALUARE_H
