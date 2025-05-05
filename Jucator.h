#ifndef JUCATOR_H
#define JUCATOR_H

#include <string>
#include <vector>

class Jucator {
private:
    std::string nume;
    std::string dataNasterii;
    std::string dataIntrareClub;
    std::string pozitie;
    int numarTricou;
    std::string nationalitate;
    std::vector<std::string> limbiVorbite;
    int goluriMarcate;
    int paseDecisive;
    int meciuriJucate;
    bool esteCapitan;

public:
    Jucator(const std::string& nume,
            const std::string& dataNasterii,
            const std::string& dataIntrareClub,
            const std::string& pozitie,
            int numarTricou,
            const std::string& nationalitate,
            const std::vector<std::string>& limbiVorbite,
            int meciuriJucate,
            bool esteCapitan);

    ~Jucator();

    void descriere() const;
    std::string getNume() const;
    std::vector<std::string> getLimbiVorbite() const;
    int calculeazaVarsta() const;
    int aniInClub() const;
    void setGoluriMarcate(int goluri);
    void setPaseDecisive(int pase);
};
#endif // JUCATOR_H