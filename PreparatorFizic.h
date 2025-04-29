#ifndef PREPARATORFIZIC_H
#define PREPARATORFIZIC_H

#include "Antrenor.h"
#include <string>
#include <vector>

class PreparatorFizic : public Antrenor {
private:
    int sedinteFitness;
    std::string tipAntrenament;
    bool antrenamenteIndividuale;
    bool monitorizareRecuperare;
    std::vector<std::string> limbiVorbite;

public:
    PreparatorFizic(const std::string& nume, int experienta,
                    int sedinteFitness,
                    const std::string& tipAntrenament,
                    bool antrenamenteIndividuale,
                    bool monitorizareRecuperare,
                    const std::vector<std::string>& limbiVorbite);

    ~PreparatorFizic();

    void descriere() const override;
    PreparatorFizic* clone() const override;
    std::vector<std::string> getLimbiVorbite() const override;

};

#endif // PREPARATORFIZIC_H
