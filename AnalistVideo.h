#ifndef ANALISTVIDEO_H
#define ANALISTVIDEO_H

#include "Antrenor.h"
#include <string>

class AnalistVideo : public Antrenor {
private:
    std::string softwareFolosit;
    int numarMeciuriAnalizate;
    int nivelDetaliuAnaliza;
    std::vector<std::string> limbiVorbite;

public:
    AnalistVideo(const std::string& nume, int experienta,
                 const std::string& softwareFolosit,
                 int numarMeciuriAnalizate,
                 int nivelDetaliuAnaliza,
                const std::vector<std::string>& limbiVorbite);

    ~AnalistVideo();

    void descriere() const override;
    AnalistVideo* clone() const override;
    std::vector<std::string> getLimbiVorbite() const override;
};

#endif
