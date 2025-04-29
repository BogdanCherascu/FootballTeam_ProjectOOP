#include "PreparatorFizic.h"
#include <iostream>

PreparatorFizic::PreparatorFizic(const std::string& nume, int experienta,
                                 int sedinteFitness,
                                 const std::string& tipAntrenament,
                                 bool antrenamenteIndividuale,
                                 bool monitorizareRecuperare,
                                 const std::vector<std::string>& limbiVorbite)
    : Antrenor(nume, experienta),
      sedinteFitness(sedinteFitness),
      tipAntrenament(tipAntrenament),
      antrenamenteIndividuale(antrenamenteIndividuale),
      monitorizareRecuperare(monitorizareRecuperare),
      limbiVorbite(limbiVorbite) {}

PreparatorFizic::~PreparatorFizic() {}

void PreparatorFizic::descriere() const {
    std::cout << "Preparator fizic: " << nume
              << "\nExperienta: " << experienta << " ani"
              << "\nSedinte/saptamana: " << sedinteFitness
              << "\nTip antrenament: " << tipAntrenament
              << "\nAntrenamente individuale: " << (antrenamenteIndividuale ? "Da" : "Nu")
              << "\nMonitorizare recuperare: " << (monitorizareRecuperare ? "Da" : "Nu")
              << "\nLimbi vorbite: ";
    for (const auto& limba : limbiVorbite)
        std::cout << limba << " ";
    std::cout << "\n----------------------\n";
}

PreparatorFizic* PreparatorFizic::clone() const {
    return new PreparatorFizic(*this);
}
std::vector<std::string> PreparatorFizic::getLimbiVorbite() const {
    return limbiVorbite;
}

