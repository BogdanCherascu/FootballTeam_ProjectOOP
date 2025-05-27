#ifndef AFISEAZAJUCATORICOMMAND_H
#define AFISEAZAJUCATORICOMMAND_H

#include "Command.h"
#include "Echipa.h"
#include <iostream>

class AfiseazaJucatoriCommand : public Command {
    Echipa& echipa;

public:
    AfiseazaJucatoriCommand(Echipa& e) : echipa(e) {}
    void executa() const override {
        echipa.afiseazaJucatori();
    }
};


#endif //AFISEAZAJUCATORICOMMAND_H
