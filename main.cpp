/*Scopul proiectului este de a implementa o aplicație în C++ care modelează o echipă de fotbal, utilizând principii fundamentale ale programării orientate pe obiect (POO): moștenire, clase abstracte, funcții virtuale, polimorfism, excepții, atribute și metode statice.
Clase implementate:
- Clasa abstractă Antrenor:
Atribute: nume, experienta
Funcții virtuale pure: descriere(), clone(), getLimbiVorbite()
Metode comune: getNume(), getExperienta()
Excepție: dacă experiența < 0

- Clase derivate din Antrenor:
1.PreparatorFizic:
Atribute: sedinteFitness, tipAntrenament, antrenamenteIndividuale, monitorizareRecuperare, limbiVorbite

2.AnalistVideo:
Atribute: softwareFolosit, numarMeciuriAnalizate, nivelDetaliuAnaliza, limbiVorbite

3.PsihologSportiv:
Atribute: sportiviConsiliati, feedbackSportivi, participaLaAntrenamente, limbiVorbite

-Clasa Jucator:
Atribute: nume, varsta, pozitie, numarTricou, nationalitate, limbiVorbite, goluriMarcate, paseDecisive, meciuriJucate, esteCapitan
Excepție: dacă goluriMarcate < 0
Metode: descriere(), getNume(), getLimbiVorbite()


- Clasa Echipa:
Atribute: numeEchipa, vectori de Jucator* și Antrenor*, limbaOficiala (static)
Funcții:
adaugaAntrenor(), adaugaJucator()
afiseazaAntrenori(), afiseazaJucatori() cu excepții dacă sunt goale
compatibilitate() – afișează antrenorii care au cel puțin o limbă comună cu toți jucătorii
numaraPreparatori(), numaraAnalisti(), numaraPsihologi() folosind dynamic_cast
setLimbaOficiala() și getLimbaOficiala() (statice)

Fișiere de intrare:
antrenori.txt – conține detalii despre fiecare antrenor (tip, nume, experiență, alte atribute, limbi vorbite)
jucatori.txt – conține detalii despre fiecare jucător

Funcționalități demonstrate:
- Moștenire multiplă și ierarhie clară de clase
- Funcții virtuale pure + polimorfism (descriere, clone, getLimbiVorbite)
- Excepții personalizate: ExceptieGoluriNegative, ExceptieNivelExperienta, ExceptieEchipaGoala
- Utilizare de dynamic_cast pentru diferențierea tipurilor
- Metode și atribute statice (limbaOficiala)
- Citire completă din fișiere .txt cu validare
- Aplicație modulară și extensibilă

Exemple afișate:
- Lista antrenorilor și jucătorilor

- Statistici (număr preparatori, analiști, psihologi)

- Compatibilitate între antrenori și jucători

- Tratate excepții cu mesaje clare în try/catch

*/

#include <iostream>
#include <fstream>
#include "PreparatorFizic.h"
#include "AnalistVideo.h"
#include "PsihologSportiv.h"
#include "Jucator.h"
#include "Echipa.h"
#include "ExceptieNivelExperienta.h"
#include "ExceptieGoluriNegative.h"
#include "ExceptieEchipaGoala.h"

int main() {
    Echipa echipa("FC Proiect");

    // Citim antrenorii
    std::ifstream finAntrenori("antrenori.txt");
    if (!finAntrenori.is_open()) {
        std::cout << "Nu am putut deschide fisierul antrenori.txt\n";
        return 1;
    }

    std::string tip;
    while (finAntrenori >> tip) {
        if (tip == "PreparatorFizic") {
            std::string nume, tipAntrenament;
            int experienta, sedinteFitness, nrLimbi;
            bool antrenamenteIndividuale, monitorizareRecuperare;
            finAntrenori >> nume >> experienta >> sedinteFitness >> tipAntrenament >> antrenamenteIndividuale
            >> monitorizareRecuperare >> nrLimbi;
            std::vector<std::string> limbi;
            for (int i = 0; i < nrLimbi; ++i) {
                std::string limba;
                finAntrenori >> limba;
                limbi.push_back(limba);
            }
            PreparatorFizic p(nume, experienta, sedinteFitness, tipAntrenament, antrenamenteIndividuale, monitorizareRecuperare, limbi);
            echipa.adaugaAntrenor(p);
        }
        else if (tip == "AnalistVideo") {
            std::string nume, softwareFolosit;
            int experienta, numarMeciuriAnalizate, nivelDetaliuAnaliza, nrLimbi;
            std::vector<std::string> limbi;
            finAntrenori >> nume >> experienta >> softwareFolosit >> numarMeciuriAnalizate >> nivelDetaliuAnaliza >> nrLimbi;
            for (int i = 0; i < nrLimbi; ++i) {
                std::string limba;
                finAntrenori >> limba;
                limbi.push_back(limba);
            }
            AnalistVideo a(nume, experienta, softwareFolosit, numarMeciuriAnalizate, nivelDetaliuAnaliza, limbi);
            echipa.adaugaAntrenor(a);
        }
        else if (tip == "PsihologSportiv") {
            std::string nume;
            int experienta, sportiviConsiliati, nrLimbi;
            float feedbackSportivi;
            bool participaLaAntrenamente;
            std::vector<std::string> limbi;
            finAntrenori >> nume >> experienta >> sportiviConsiliati >> feedbackSportivi >> participaLaAntrenamente>> nrLimbi;
            for (int i = 0; i < nrLimbi; ++i) {
                std::string limba;
                finAntrenori >> limba;
                limbi.push_back(limba);
            }
            PsihologSportiv ps(nume, experienta, sportiviConsiliati, feedbackSportivi, participaLaAntrenamente, limbi);
            echipa.adaugaAntrenor(ps);
        }
    }
    finAntrenori.close();

    // Citim jucatorii
    std::ifstream finJucatori("jucatori.txt");
    if (!finJucatori.is_open()) {
        std::cout << "Nu am putut deschide fisierul jucatori.txt\n";
        return 1;
    }

    std::string nume, pozitie, nationalitate;
    int varsta, numarTricou, nrLimbi, goluriMarcate, paseDecisive, meciuriJucate;
    bool esteCapitan;

    while (finJucatori >> nume >> varsta >> pozitie >> numarTricou >> nationalitate >> nrLimbi) {
        std::vector<std::string> limbi;
        for (int i = 0; i < nrLimbi; ++i) {
            std::string limba;
            finJucatori >> limba;
            limbi.push_back(limba);
        }
        finJucatori >> goluriMarcate >> paseDecisive >> meciuriJucate >> esteCapitan;

        Jucator j(nume, varsta, pozitie, numarTricou, nationalitate, limbi, goluriMarcate, paseDecisive, meciuriJucate, esteCapitan);
        echipa.adaugaJucator(j);
    }
    finJucatori.close();

    // Afisam ce am citit
    std::cout << "Limba oficiala a clubului este: " << Echipa::getLimbaOficiala() << "\n";
    std::cout << "\n=== Antrenori ===\n";
    try {
        echipa.afiseazaAntrenori();
    } catch (const ExceptieEchipaGoala& e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n=== Jucatori ===\n";
    try {
        echipa.afiseazaJucatori();
    } catch (const ExceptieEchipaGoala& e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n=== Statistici ===\n";
    std::cout << "Numar Preparatori Fizici: " << echipa.numaraPreparatori() << "\n";
    std::cout << "Numar Analisti Video: " << echipa.numaraAnalisti() << "\n";
    std::cout << "Numar Psihologi Sportivi: " << echipa.numaraPsihologi() << "\n";
    std::cout << "\n=== Antrenorii compatibili cu toti jucatorii ===\n";
    echipa.compatibilitate();

    return 0;
}
