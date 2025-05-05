#ifndef ECHIPA_H
#define ECHIPA_H

#include "Antrenor.h"
#include "Jucator.h"
#include <vector>
#include <string>

class Echipa {
private:
    std::string numeEchipa;
    std::vector<Antrenor*> antrenori;
    std::vector<Jucator*> jucatori;
    static std::string limbaOficiala;


public:
    Echipa();
    Echipa(const std::string& numeEchipa);
    Echipa(const Echipa& other);
    Echipa& operator=(const Echipa& other);
    ~Echipa();

    void adaugaAntrenor(const Antrenor& a);
    void adaugaJucator(const Jucator& j);

    void afiseazaAntrenori() const;
    void afiseazaJucatori() const;

    static void setLimbaOficiala(const std::string& limba);
    static std::string getLimbaOficiala();

    static void setNumeEchipa(const std::string& nume);
    static std::string getNumeEchipa();

    int numaraPreparatori() const;
    int numaraAnalisti() const;
    int numaraPsihologi() const;
    void compatibilitate() const;
    std::vector<Jucator*>& getJucatori();

};

#endif // ECHIPA_H
