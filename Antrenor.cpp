#include "Antrenor.h"
#include "ExceptieNivelExperienta.h" // adaugăm include-ul excepției
Antrenor::Antrenor(const std::string& nume, int experienta)
    : nume(nume), experienta(experienta) {
    if (experienta < 0) {
        throw ExceptieNivelExperienta();
    }
}

Antrenor::~Antrenor() {}

int Antrenor::getExperienta() const {
    return experienta;
}
std::string Antrenor::getNume() const {
    return nume;
}
