#include "AnalistVideo.h"
#include <iostream>

AnalistVideo::AnalistVideo(const std::string& nume, int experienta,
                           const std::string& softwareFolosit,
                           int numarMeciuriAnalizate,
                           int nivelDetaliuAnaliza,
                           const std::vector<std::string>& limbiVorbite)
    : Antrenor(nume, experienta),
      softwareFolosit(softwareFolosit),
      numarMeciuriAnalizate(numarMeciuriAnalizate),
      nivelDetaliuAnaliza(nivelDetaliuAnaliza),
      limbiVorbite(limbiVorbite){}

AnalistVideo::~AnalistVideo() {}

void AnalistVideo::descriere() const {
    std::cout << "Analist Video: " << nume
              << "\nExperienta: " << experienta << " ani"
              << "\nSoftware folosit: " << softwareFolosit
              << "\nNumar meciuri analizate: " << numarMeciuriAnalizate
              << "\nNivel detaliu analiza (1-10): " << nivelDetaliuAnaliza
              << "\nLimbi vorbite: ";
    for (const auto& limba : limbiVorbite)
        std::cout << limba << " ";
    std::cout << "\n----------------------\n";
}

AnalistVideo* AnalistVideo::clone() const {
    return new AnalistVideo(*this);
}
std::vector<std::string> AnalistVideo::getLimbiVorbite() const {
    return limbiVorbite;
}

