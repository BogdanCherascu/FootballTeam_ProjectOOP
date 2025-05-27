#include <iostream>
#include <fstream>
#include <vector>
#include "PreparatorFizic.h"
#include "AnalistVideo.h"
#include "PsihologSportiv.h"
#include "Jucator.h"
#include "Echipa.h"
#include "Sezon.h"
#include "Evaluare.h"
#include "AfisareEval.h"
#include "AntrenorFactory.h"
#include "ExceptieNivelExperienta.h"
#include "ExceptieGoluriNegative.h"
#include "ExceptieEchipaGoala.h"
#include "Logger.h"
#include "AfiseazaJucatoriCommand.h"


int main() {
    Echipa echipa("FC Proiect");
    Logger::getInstance().log("Echipa a fost creata.");


    Echipa::setLimbaOficiala("Romana");

    // Citire antrenori
    std::ifstream finAntrenori("antrenori.txt");
    if (!finAntrenori.is_open()) {
        std::cerr << "Nu am putut deschide fisierul antrenori.txt\n";
        return 1;
    }else{Logger::getInstance().log("Fisierul antrenori.txt a fost incarcat.");}



    std::string tip;
    while (finAntrenori >> tip) {
        try {
            Antrenor* a = AntrenorFactory::creeaza(tip, finAntrenori);
            echipa.adaugaAntrenor(*a);
            delete a;
        } catch (const std::exception& e) {
            std::cerr << "Eroare creare antrenor: " << e.what() << "\n";
        }
    }

    finAntrenori.close();

    // Citire jucatori
    std::ifstream finJucatori("jucatori.txt");
    if (!finJucatori.is_open()) {
        std::cerr << "Nu am putut deschide fisierul jucatori.txt\n";
        return 1;
    }else{Logger::getInstance().log("Fisierul jucatori.txt a fost incarcat.");}

    std::string nume, dataNasterii, dataIntrare, pozitie, nationalitate;
    int numarTricou, nrLimbi, esteCapitan;
    while (finJucatori >> nume >> dataNasterii >> dataIntrare >> pozitie >> numarTricou >> nationalitate >> nrLimbi) {
        std::vector<std::string> limbi;
        for (int i = 0; i < nrLimbi; ++i) {
            std::string limba;
            finJucatori >> limba;
            limbi.push_back(limba);
        }
        finJucatori >> esteCapitan;

        try {
            Jucator j(nume, dataNasterii, dataIntrare, pozitie, numarTricou, nationalitate, limbi, esteCapitan);
            echipa.adaugaJucator(j);
        } catch (const std::exception& e) {
            std::cerr << "Eroare jucator: " << e.what() << "\n";
        }
    }
    finJucatori.close();


    Sezon sezon;
    Logger::getInstance().log("Se genereaza sezonul...");
    sezon.genereazaSezon(echipa);
    sezon.actualizeazaStatisticiJucatori(echipa);
    Logger::getInstance().log("Statistici jucatori actualizate dupa sezon.");
    std::vector<int> scoruri;
    std::vector<Jucator*> jucatori = echipa.getJucatori();

    for (Jucator* j : jucatori) {
        int scor = j->getGoluriMarcate() * 3 + j->getPaseDecisive() * 2;
        scoruri.push_back(scor);
    }






    std::cout << "\n--- INFORMATII ECHIPA ---\n";
    std::cout << "Limba oficiala: " << Echipa::getLimbaOficiala() << "\n\n";

    try {
        echipa.afiseazaAntrenori();
        Command* cmd = new AfiseazaJucatoriCommand(echipa);
        cmd->executa();
        delete cmd;

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

    std::cout << "\n--- SCORURI CALCULATE ---\n";
    afiseazaEvaluare(jucatori, scoruri);

    Logger::getInstance().log("Programul s-a incheiat cu succes.");
    return 0;
}
