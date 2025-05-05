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
- Atribute: 
  - `nume`, `pozitie`, `numarTricou`, `nationalitate`, `limbiVorbite`, `meciuriJucate`, `esteCapitan`
  - `dataNasterii` – pentru calcularea vârstei în timp real
  - `dataIntrareClub` – pentru calculul vechimii în club
  - `goluriMarcate`, `paseDecisive` – calculate automat pe baza meciurilor
- Excepție: dacă `goluriMarcate < 0`
- Metode: `descriere()`, `getNume()`, `getLimbiVorbite()`, `calculeazaVarsta()`, `calculeazaVechime()`

###  Clasa `Echipa`
- Atribute: `numeEchipa`, vectori de `Jucator*` și `Antrenor*`, `limbaOficiala` (static)
- Funcții principale:
  - `adaugaAntrenor()`, `adaugaJucator()`
  - `afiseazaAntrenori()`, `afiseazaJucatori()` (cu excepție dacă sunt goale)
  - `compatibilitate()` – afișează antrenorii care se pot înțelege cu toți jucătorii
  - `numaraPreparatori()`, `numaraAnalisti()`, `numaraPsihologi()` (cu `dynamic_cast`)
  - `setLimbaOficiala()` și `getLimbaOficiala()` (statice)
  - `getJucatori()` – acces direct pentru clasele care prelucrează statistici

### Clasa `Meci`
- Atribute: `numeAdversar`, vector de 11 `Jucator*`, număr de goluri și pase pentru fiecare jucător
- Fiecare meci actualizează automat statistici jucători

### Clasa `Sezon`
- Atribute: 32 de obiecte `Meci`
- Metode:
  - `genereazaSezon()` – generează 32 de meciuri random cu adversari și jucători aleși aleator
  - `actualizeazaStatisticiJucatori()` – parcurge meciurile și calculează goluri/pase pentru fiecare jucător

## Fișiere de intrare
- `antrenori.txt` – detalii despre fiecare antrenor (tip, nume, experiență, alte atribute, limbi vorbite)
- `jucatori.txt` – detalii despre fiecare jucător (inclusiv data nașterii și data intrării în club)

## Funcționalități demonstrate
- Moștenire și ierarhie de clase
- Funcții virtuale pure și polimorfism (`descriere`, `clone`, `getLimbiVorbite`)
- Excepții personalizate: `ExceptieGoluriNegative`, `ExceptieNivelExperienta`, `ExceptieEchipaGoala`
- `dynamic_cast` pentru diferențierea tipurilor de antrenori
- Atribute și metode statice (`limbaOficiala`)
- Calculul vârstei în timp real din data nașterii
- Calculul vechimii în club
- Generare automată a unui sezon de meciuri
- Actualizare automată a statisticilor jucătorilor în funcție de performanțele lor în meciuri
- Citire completă din fișiere `.txt`
- Aplicație modulară, extensibilă, robustă

##  Exemple afișate
- Lista antrenorilor și jucătorilor
- Statistici despre echipă (număr preparatori, analiști, psihologi)
- Vârsta și vechimea fiecărui jucător în club
- Antrenori compatibili cu toți jucătorii
- Statistici după finalizarea sezonului
- Tratate excepții în `try/catch` cu mesaje clare

## Bibliografie
- Codebeauty YouTube Channel: https://www.youtube.com/@CodeBeauty  
- Material GitHub mcmarius: https://github.com/mcmarius/poo/tree/master/tema-2  
- Tutorial C++ W3Schools: https://www.w3schools.com/cpp/default.asp  
- Generare fișiere text folosind AI
