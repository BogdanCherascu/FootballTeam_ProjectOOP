#include "Echipa.h"
#include <iostream>
#include "ExceptieEchipaGoala.h"
#include "PreparatorFizic.h"
#include "AnalistVideo.h"
#include "PsihologSportiv.h"


std::string Echipa::limbaOficiala = "Romana";


Echipa::Echipa() : numeEchipa("Anonim") {}

Echipa::Echipa(const std::string& numeEchipa) : numeEchipa(numeEchipa) {}

Echipa::Echipa(const Echipa& other) : numeEchipa(other.numeEchipa) {
    for (const auto& antrenor : other.antrenori) {
        antrenori.push_back(antrenor->clone());
    }

}

Echipa& Echipa::operator=(const Echipa& other) {
    if (this != &other) {
        for (auto& a : antrenori) {
            delete a;
        }
        antrenori.clear();

        numeEchipa = other.numeEchipa;
        for (const auto& antrenor : other.antrenori) {
            antrenori.push_back(antrenor->clone());
        }
    }
    return *this;
}

Echipa::~Echipa() {
    for (auto& a : antrenori) {
        delete a;
    }
}

void Echipa::adaugaAntrenor(const Antrenor& a) {
    antrenori.push_back(a.clone());
}
void Echipa::adaugaJucator(const Jucator& j) {
    jucatori.push_back(new Jucator(j));
}

void Echipa::afiseazaAntrenori() const {
    if (antrenori.empty()) {
        throw ExceptieEchipaGoala();
    }
    for (const auto& a : antrenori) {
        a->descriere();
    }
}

void Echipa::afiseazaJucatori() const {
    if (jucatori.empty()) {
        throw ExceptieEchipaGoala();
    }
    for (const auto& j : jucatori) {
        j->descriere();
    }
}

void Echipa::setLimbaOficiala(const std::string& limba) {
    limbaOficiala = limba;
}

std::string Echipa::getLimbaOficiala() {
    return limbaOficiala;
}

int Echipa::numaraPreparatori() const {
    int count = 0;
    for (const auto& a : antrenori) {
        if (dynamic_cast<const PreparatorFizic*>(a)) {
            count++;
        }
    }
    return count;
}

int Echipa::numaraAnalisti() const {
    int count = 0;
    for (const auto& a : antrenori) {
        if (dynamic_cast<const AnalistVideo*>(a)) {
            count++;
        }
    }
    return count;
}

int Echipa::numaraPsihologi() const {
    int count = 0;
    for (const auto& a : antrenori) {
        if (dynamic_cast<const PsihologSportiv*>(a)) {
            count++;
        }
    }
    return count;
}
void Echipa::compatibilitate() const {
    if (antrenori.empty() || jucatori.empty()) {
        std::cout << "Nu exista antrenori sau jucatori pentru verificare.\n";
        return;
    }

    for (const auto& a : antrenori) {
        bool seIntelegeCuToti = true;

        for (const auto& j : jucatori) {
            bool existaLimbacomuna = false;

            for (const auto& limbaAntrenor : a->getLimbiVorbite()) {
                for (const auto& limbaJucator : j->getLimbiVorbite()) {
                    if (limbaAntrenor == limbaJucator) {
                        existaLimbacomuna = true;
                        break;
                    }
                }
                if (existaLimbacomuna) break;
            }

            if (!existaLimbacomuna) {
                seIntelegeCuToti = false;
                break;
            }
        }

        if (seIntelegeCuToti) {
            std::cout <<a->getNume() << "\n";
        }
    }
}

