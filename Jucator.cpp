#include "Jucator.h"
#include "ExceptieGoluriNegative.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

Jucator::Jucator(const std::string& nume,
                 const std::string& dataNasterii,
                 const std::string& dataIntrareClub,
                 const std::string& pozitie,
                 int numarTricou,
                 const std::string& nationalitate,
                 const std::vector<std::string>& limbiVorbite,
                 bool esteCapitan)
    : nume(nume), dataNasterii(dataNasterii), dataIntrareClub(dataIntrareClub), pozitie(pozitie),
      numarTricou(numarTricou), nationalitate(nationalitate), limbiVorbite(limbiVorbite),
      goluriMarcate(0), paseDecisive(0), esteCapitan(esteCapitan) {}

Jucator::~Jucator() {}

int Jucator::calculeazaVarsta() const {
    std::tm tm = {};
    std::istringstream ss(dataNasterii);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    std::time_t acum = std::time(nullptr);
    std::tm* tmacum = std::localtime(&acum);

    int varsta = tmacum->tm_year - tm.tm_year;
    if (tmacum->tm_mon < tm.tm_mon ||
        (tmacum->tm_mon == tm.tm_mon && tmacum->tm_mday < tm.tm_mday))
        varsta--;

    return varsta;
}

int Jucator::aniInClub() const {
    std::tm tm = {};
    std::istringstream ss(dataIntrareClub);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    std::time_t acum = std::time(nullptr);
    std::tm* tmacum = std::localtime(&acum);

    int ani = tmacum->tm_year - tm.tm_year;
    if (tmacum->tm_mon < tm.tm_mon ||
        (tmacum->tm_mon == tm.tm_mon && tmacum->tm_mday < tm.tm_mday))
        ani--;

    return ani;
}

void Jucator::descriere() const {
    std::cout << "Jucator: " << nume
              << "\nVarsta: " << calculeazaVarsta() << " ani"
              << "\nAni in club: " << aniInClub()
              << "\nPozitie: " << pozitie
              << "\nNumar tricou: " << numarTricou
              << "\nNationalitate: " << nationalitate
              << "\nLimbi vorbite: ";
    for (const auto& limba : limbiVorbite)
        std::cout << limba << " ";
    std::cout << "\nEste capitan: " << (esteCapitan ? "Da" : "Nu")
              << "\n----------------------\n";
}

std::string Jucator::getNume() const {
    return nume;
}

std::vector<std::string> Jucator::getLimbiVorbite() const {
    return limbiVorbite;
}
int Jucator::getGoluriMarcate() const {
    return goluriMarcate;
}

int Jucator::getPaseDecisive() const {
    return paseDecisive;
}

void Jucator::setGoluriMarcate(int goluri) {
    goluriMarcate = goluri;
}

void Jucator::setPaseDecisive(int pase) {
    paseDecisive = pase;
}

