#include "PsihologSportiv.h"
#include <iostream>

PsihologSportiv::PsihologSportiv(const std::string& nume, int experienta,
                                 int sportiviConsiliati,
                                 float feedbackSportivi,
                                 bool participaLaAntrenamente,
                                 const std::vector<std::string>& limbiVorbite)
    : Antrenor(nume, experienta),
      sportiviConsiliati(sportiviConsiliati),
      feedbackSportivi(feedbackSportivi),
      participaLaAntrenamente(participaLaAntrenamente),
      limbiVorbite(limbiVorbite){}

PsihologSportiv::~PsihologSportiv() {}

void PsihologSportiv::descriere() const {
    std::cout << "Psiholog Sportiv: " << nume
              << "\nExperienta: " << experienta << " ani"
              << "\nSportivi consiliati: " << sportiviConsiliati
              << "\nFeedback sportivi (1-10): " << feedbackSportivi
              << "\nParticipa la antrenamente: " << (participaLaAntrenamente ? "Da" : "Nu")
              << "\nLimbi vorbite: ";
    for (const auto& limba : limbiVorbite)
        std::cout << limba << " ";
    std::cout << "\n----------------------\n";
}


PsihologSportiv* PsihologSportiv::clone() const {
    return new PsihologSportiv(*this);
}
std::vector<std::string> PsihologSportiv::getLimbiVorbite() const {
    return limbiVorbite;
}
