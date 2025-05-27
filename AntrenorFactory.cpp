#include "AntrenorFactory.h"

Antrenor* AntrenorFactory::creeaza(const std::string& tip, std::istream& in) {
    std::string nume;
    int experienta;
    in >> nume >> experienta;

    int nrLimbi;
    std::vector<std::string> limbi;

    if (tip == "PreparatorFizic") {
        int sedinte;
        std::string tipAntr;
        bool individuale, recuperare;
        in >> sedinte >> tipAntr >> individuale >> recuperare >> nrLimbi;
        for (int i = 0; i < nrLimbi; ++i) {
            std::string limba;
            in >> limba;
            limbi.push_back(limba);
        }
        return new PreparatorFizic(nume, experienta, sedinte, tipAntr, individuale, recuperare, limbi);
    }

    if (tip == "AnalistVideo") {
        std::string software;
        int meciuri, detaliu;
        in >> software >> meciuri >> detaliu >> nrLimbi;
        for (int i = 0; i < nrLimbi; ++i) {
            std::string limba;
            in >> limba;
            limbi.push_back(limba);
        }
        return new AnalistVideo(nume, experienta, software, meciuri, detaliu, limbi);
    }

    if (tip == "PsihologSportiv") {
        int sportivi;
        float feedback;
        bool participa;
        in >> sportivi >> feedback >> participa >> nrLimbi;
        for (int i = 0; i < nrLimbi; ++i) {
            std::string limba;
            in >> limba;
            limbi.push_back(limba);
        }
        return new PsihologSportiv(nume, experienta, sportivi, feedback, participa, limbi);
    }

    throw std::runtime_error("Tip necunoscut de antrenor: " + tip);
}
