#include "Sezon.h"
#include <iostream>
#include <algorithm>

void Sezon::genereazaSezon(Echipa& echipa) {
    std::vector<std::string> adversari = {
        "Steaua", "Dinamo", "Rapid", "CFR Cluj", "Farul Constanta",
        "FCU Craiova", "Universitatea Craiova", "UTA Arad", "Petrolul",
        "Sepsi", "Voluntari", "Chindia", "Botosani", "Hermannstadt",
        "Clinceni", "Mioveni", "FC Brasov", "Unirea Slobozia",
        "Concordia", "Gloria Buzau", "Poli Iasi", "Otelul Galati",
        "Metaloglobus", "Progresul", "Ripensia", "CSM Resita",
        "Viitorul Tg Jiu", "FC Arges", "CS Tunari", "Pandurii",
        "CS Afumati", "CS Mioveni"
    };

    auto jucatori = echipa.getJucatori();
    for (int i = 0; i < 32; ++i) {
        std::random_shuffle(jucatori.begin(), jucatori.end());
        std::vector<Jucator*> titulari(jucatori.begin(), jucatori.begin() + std::min(11, (int)jucatori.size()));
        Meci m(adversari[i], titulari);
        meciuri.push_back(m);
    }
}

void Sezon::actualizeazaStatisticiJucatori(Echipa& echipa) {
    auto& jucatori = echipa.getJucatori();
    for (Jucator* j : jucatori) {
        int totalGoluri = 0;
        int totalPase = 0;
        for (const auto& m : meciuri) {
            auto goluriMap = m.getGoluri();
            auto paseMap = m.getPaseDecisive();
            if (goluriMap.count(j)) totalGoluri += goluriMap[j];
            if (paseMap.count(j)) totalPase += paseMap[j];
        }
        j->setGoluriMarcate(totalGoluri);
        j->setPaseDecisive(totalPase);
    }
}

void Sezon::afiseazaRezumatMeciuri() const {
    for (const auto& m : meciuri) {
        std::cout << "\nMeci contra: " << m.getAdversar() << "\n";
        for (Jucator* j : m.getTitulari()) {
            std::cout << " - " << j->getNume()
                      << " | Goluri: " << m.getGoluri().at(j)
                      << " | Pase decisive: " << m.getPaseDecisive().at(j)
                      << "\n";
        }
    }
}
