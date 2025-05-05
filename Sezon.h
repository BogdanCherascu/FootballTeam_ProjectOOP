#ifndef SEZON_H
#define SEZON_H

#include "Meci.h"
#include "Echipa.h"
#include <vector>
#include <string>

class Sezon {
private:
    std::vector<Meci> meciuri;

public:
    void genereazaSezon(Echipa& echipa);
    void actualizeazaStatisticiJucatori(Echipa& echipa);
    void afiseazaRezumatMeciuri() const;
};

#endif //SEZON_H
