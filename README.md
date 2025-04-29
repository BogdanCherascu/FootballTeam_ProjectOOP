# Proiect POO - Moșteniri și Excepții

## Obiectivul proiectului
Scopul proiectului este de a implementa o aplicație în C++ care modelează o echipă de fotbal, utilizând principii fundamentale ale programării orientate pe obiect (POO): moștenire, clase abstracte, funcții virtuale, polimorfism, excepții, atribute și metode statice.

## Clase implementate

###  Clasa abstractă `Antrenor`
- Atribute: `nume`, `experienta`
- Funcții virtuale pure: `descriere()`, `clone()`, `getLimbiVorbite()`
- Metode comune: `getNume()`, `getExperienta()`
- Excepție: dacă experiența < 0

###  Clase derivate din `Antrenor`:
- `PreparatorFizic`: `sedinteFitness`, `tipAntrenament`, `antrenamenteIndividuale`, `monitorizareRecuperare`, `limbiVorbite`
- `AnalistVideo`: `softwareFolosit`, `numarMeciuriAnalizate`, `nivelDetaliuAnaliza`, `limbiVorbite`
- `PsihologSportiv`: `sportiviConsiliati`, `feedbackSportivi`, `participaLaAntrenamente`, `limbiVorbite`

###  Clasa `Jucator`
- Atribute: `nume`, `varsta`, `pozitie`, `numarTricou`, `nationalitate`, `limbiVorbite`, `goluriMarcate`, `paseDecisive`, `meciuriJucate`, `esteCapitan`
- Excepție: dacă `goluriMarcate < 0`
- Metode: `descriere()`, `getNume()`, `getLimbiVorbite()`

###  Clasa `Echipa`
- Atribute: `numeEchipa`, vectori de `Jucator*` și `Antrenor*`, `limbaOficiala` (static)
- Funcții principale:
  - `adaugaAntrenor()`, `adaugaJucator()`
  - `afiseazaAntrenori()`, `afiseazaJucatori()` (cu excepție dacă sunt goale)
  - `compatibilitate()` – afișează antrenorii care se pot înțelege cu toți jucătorii
  - `numaraPreparatori()`, `numaraAnalisti()`, `numaraPsihologi()` (cu `dynamic_cast`)
  - `setLimbaOficiala()` și `getLimbaOficiala()` (statice)

## Fișiere de intrare
- `antrenori.txt` – detalii despre fiecare antrenor (tip, nume, experiență, alte atribute, limbi vorbite)
- `jucatori.txt` – detalii despre fiecare jucător

## Funcționalități demonstrate
- Moștenire și ierarhie de clase
- Funcții virtuale pure și polimorfism (`descriere`, `clone`, `getLimbiVorbite`)
- Excepții personalizate: `ExceptieGoluriNegative`, `ExceptieNivelExperienta`, `ExceptieEchipaGoala`
- `dynamic_cast` pentru diferențierea tipurilor de antrenori
- Metode și atribute statice (`limbaOficiala`)
- Citire completă din fișiere `.txt`
- Aplicație modulară, extensibilă, robustă

##  Exemple afișate
- Lista antrenorilor și jucătorilor
- Statistici despre echipă (număr preparatori, analiști, psihologi)
- Antrenori compatibili cu toți jucătorii
- Tratate excepții în `try/catch` cu mesaje clare

## Concluzie
Proiectul demonstrează implementarea corectă a principiilor OOP în C++. Codul este modular, extensibil și tratează cazuri de eroare prin excepții. Funcționalitatea este validată prin input din fișiere și afișări descriptive în consolă.
