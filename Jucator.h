#ifndef JUCATOR_H
#define JUCATOR_H

#include <string>
#include <vector>

class Jucator {
private:
    std::string nume;
    int varsta;
    std::string pozitie;
    int numarTricou;
    std::string nationalitate;
    std::vector<std::string> limbiVorbite;
    int goluriMarcate;
    int paseDecisive;
    int meciuriJucate;
    bool esteCapitan;

public:
    Jucator(const std::string& nume, int varsta, const std::string& pozitie,
            int numarTricou, const std::string& nationalitate,
            const std::vector<std::string>& limbiVorbite,
            int goluriMarcate, int paseDecisive,
            int meciuriJucate, bool esteCapitan);

    ~Jucator();

    void descriere() const;
    std::vector<std::string> getLimbiVorbite() const;
    std::string getNume() const;
};

#endif // JUCATOR_H
