#include "Jucator.h"
#include <iostream>
#include "ExceptieGoluriNegative.h" // adaugăm include-ul excepției

Jucator::Jucator(const std::string& nume, int varsta, const std::string& pozitie,
                 int numarTricou, const std::string& nationalitate,
                 const std::vector<std::string>& limbiVorbite,
                 int goluriMarcate, int paseDecisive,
                 int meciuriJucate, bool esteCapitan)
    : nume(nume), varsta(varsta), pozitie(pozitie), numarTricou(numarTricou),
      nationalitate(nationalitate), limbiVorbite(limbiVorbite),
      goluriMarcate(goluriMarcate), paseDecisive(paseDecisive),
      meciuriJucate(meciuriJucate), esteCapitan(esteCapitan) {
    if (goluriMarcate < 0) {
        throw ExceptieGoluriNegative();
    }
}

Jucator::~Jucator() {}

void Jucator::descriere() const {
    std::cout << "Jucator: " << nume
              << "\nVarsta: " << varsta
              << "\nPozitie: " << pozitie
              << "\nNumar tricou: " << numarTricou
              << "\nNationalitate: " << nationalitate
              << "\nLimbi vorbite: ";
    for (const auto& limba : limbiVorbite) {
        std::cout << limba << " ";
    }
    std::cout << "\nGoluri marcate: " << goluriMarcate
              << "\nPase decisive: " << paseDecisive
              << "\nMeciuri jucate: " << meciuriJucate
              << "\nEste capitan: " << (esteCapitan ? "Da" : "Nu")
              << "\n----------------------\n";
}
std::vector<std::string> Jucator::getLimbiVorbite() const {
    return limbiVorbite;
}
std::string Jucator::getNume() const {
    return nume;
}

