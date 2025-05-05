#include <iostream>
#include <fstream>
#include <vector>
#include "PreparatorFizic.h"
#include "AnalistVideo.h"
#include "PsihologSportiv.h"
#include "Jucator.h"
#include "Echipa.h"
#include "Sezon.h"
#include "ExceptieNivelExperienta.h"
#include "ExceptieGoluriNegative.h"
#include "ExceptieEchipaGoala.h"

int main() {
    Echipa echipa("FC Proiect");
    Echipa::setLimbaOficiala("Romana");

    // Citire antrenori
    std::ifstream finAntrenori("antrenori.txt");
    if (!finAntrenori.is_open()) {
        std::cerr << "Nu am putut deschide fisierul antrenori.txt\n";
        return 1;
    }

    std::string tip;
    while (finAntrenori >> tip) {
        try {
            std::string nume;
            int experienta;
            finAntrenori >> nume >> experienta;
            int nr;
            std::vector<std::string> limbi;

            if (tip == "PreparatorFizic") {
                int sedinte;
                std::string tipAntr;
                bool individuale, recuperare;
                finAntrenori >> sedinte >> tipAntr >> individuale >> recuperare >> nr;
                for (int i = 0; i < nr; ++i) {
                    std::string limba;
                    finAntrenori >> limba;
                    limbi.push_back(limba);
                }
                PreparatorFizic p(nume, experienta, sedinte, tipAntr, individuale, recuperare, limbi);
                echipa.adaugaAntrenor(p);
            }
            else if (tip == "AnalistVideo") {
                std::string software;
                int meciuri, detaliu;
                finAntrenori >> software >> meciuri >> detaliu >> nr;
                for (int i = 0; i < nr; ++i) {
                    std::string limba;
                    finAntrenori >> limba;
                    limbi.push_back(limba);
                }
                AnalistVideo a(nume, experienta, software, meciuri, detaliu, limbi);
                echipa.adaugaAntrenor(a);
            }
            else if (tip == "PsihologSportiv") {
                int sportivi;
                float feedback;
                bool participa;
                finAntrenori >> sportivi >> feedback >> participa >> nr;
                for (int i = 0; i < nr; ++i) {
                    std::string limba;
                    finAntrenori >> limba;
                    limbi.push_back(limba);
                }
                PsihologSportiv ps(nume, experienta, sportivi, feedback, participa, limbi);
                echipa.adaugaAntrenor(ps);
            }
        } catch (const std::exception& e) {
            std::cerr << "Eroare antrenor: " << e.what() << "\n";
        }
    }
    finAntrenori.close();

    // Citire jucatori
    std::ifstream finJucatori("jucatori.txt");
    if (!finJucatori.is_open()) {
        std::cerr << "Nu am putut deschide fisierul jucatori.txt\n";
        return 1;
    }

    std::string nume, dataNasterii, dataIntrare, pozitie, nationalitate;
    int numarTricou, nrLimbi, meciuriJucate, esteCapitan;
    while (finJucatori >> nume >> dataNasterii >> dataIntrare >> pozitie >> numarTricou >> nationalitate >> nrLimbi) {
        std::vector<std::string> limbi;
        for (int i = 0; i < nrLimbi; ++i) {
            std::string limba;
            finJucatori >> limba;
            limbi.push_back(limba);
        }
        finJucatori >> meciuriJucate >> esteCapitan;

        try {
            Jucator j(nume, dataNasterii, dataIntrare, pozitie, numarTricou, nationalitate, limbi, meciuriJucate, esteCapitan);
            echipa.adaugaJucator(j);
        } catch (const std::exception& e) {
            std::cerr << "Eroare jucator: " << e.what() << "\n";
        }
    }
    finJucatori.close();

    // Sezon si meciuri
    Sezon sezon;
    sezon.genereazaSezon(echipa);
    sezon.actualizeazaStatisticiJucatori(echipa);

    // Afisari generale
    std::cout << "\n--- INFORMATII ECHIPA ---\n";
    std::cout << "Limba oficiala: " << Echipa::getLimbaOficiala() << "\n\n";

    try {
        echipa.afiseazaAntrenori();
        echipa.afiseazaJucatori();
    } catch (const ExceptieEchipaGoala& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "\n--- STATISTICI ---\n";
    std::cout << "Preparatori fizici: " << echipa.numaraPreparatori() << "\n";
    std::cout << "Analisti video: " << echipa.numaraAnalisti() << "\n";
    std::cout << "Psihologi sportivi: " << echipa.numaraPsihologi() << "\n";

    std::cout << "\n--- COMPATIBILITATE ---\n";
    echipa.compatibilitate();

    std::cout << "\n--- REZUMAT SEZON ---\n";
    sezon.afiseazaRezumatMeciuri();

    return 0;
}
