#ifndef PSIHOLOGSPORTIV_H
#define PSIHOLOGSPORTIV_H

#include "Antrenor.h"
#include <string>

class PsihologSportiv : public Antrenor {
private:
    int sportiviConsiliati;
    float feedbackSportivi; // scor mediu din partea sportivilor
    bool participaLaAntrenamente;
    std::vector<std::string> limbiVorbite;

public:
    PsihologSportiv(const std::string& nume, int experienta,
                    int sportiviConsiliati,
                    float feedbackSportivi,
                    bool participaLaAntrenamente,
                    const std::vector<std::string>& limbiVorbite);

    ~PsihologSportiv();

    void descriere() const override;
    PsihologSportiv* clone() const override;
    std::vector<std::string> getLimbiVorbite() const override;

};

#endif // PSIHOLOGSPORTIV_H
