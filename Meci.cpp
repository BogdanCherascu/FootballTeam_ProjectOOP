#include "Meci.h"
#include <cstdlib>
#include <ctime>

Meci::Meci(const std::string& adversar, const std::vector<Jucator*>& titulari)
    : echipaAdversara(adversar), titulari(titulari) {
    simuleazaStatistici();
}

void Meci::simuleazaStatistici() {
    std::srand(std::time(nullptr));
    for (Jucator* j : titulari) {
        int goluriJ = std::rand() % 3;
        int paseJ = std::rand() % 3;
        goluri[j] = goluriJ;
        paseDecisive[j] = paseJ;
    }
}

const std::string& Meci::getAdversar() const {
    return echipaAdversara;
}

const std::vector<Jucator*>& Meci::getTitulari() const {
    return titulari;
}

const std::map<Jucator*, int>& Meci::getGoluri() const {
    return goluri;
}

const std::map<Jucator*, int>& Meci::getPaseDecisive() const {
    return paseDecisive;
}


