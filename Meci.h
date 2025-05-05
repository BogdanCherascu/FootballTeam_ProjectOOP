#ifndef MECI_H
#define MECI_H

#include "Jucator.h"
#include <string>
#include <vector>
#include <map>

class Meci {
private:
    std::string echipaAdversara;
    std::vector<Jucator*> titulari;
    std::map<Jucator*, int> goluri;
    std::map<Jucator*, int> paseDecisive;

public:
    Meci(const std::string& adversar, const std::vector<Jucator*>& titulari);

    void simuleazaStatistici();
    const std::string& getAdversar() const;
    const std::vector<Jucator*>& getTitulari() const;
    const std::map<Jucator*, int>& getGoluri() const;
    const std::map<Jucator*, int>& getPaseDecisive() const;
};

#endif //MECI_H
