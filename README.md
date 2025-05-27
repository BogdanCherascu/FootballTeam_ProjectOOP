# Proiect POO - Moșteniri, Excepții și Programare Generică (Tema 3)

## Obiectivul proiectului
Scopul proiectului este de a modela o echipă de fotbal în C++, utilizând principii fundamentale ale programării orientate pe obiect (POO), tratând excepții, lucrând cu moșteniri și ierarhii de clase, dar și aplicând concepte avansate precum:
- Șabloane de funcții și clase (`template`)
- Design patterns (Factory, Singleton, Prototype, Command)
- Principii de extensibilitate (fără modificarea codului existent)

---

## Cerințe tema 3 – și cum au fost îndeplinite

### Clasă `template`
- Am creat `Evaluare<T>`, o clasă `template` care atașează unui `Jucator*` un scor generic `T`.
- Atributul `scor` este de tip `T`.
- Metoda `afiseaza()` utilizează `T` pentru a afișa evaluarea.
- Clasa este izolată și nu modifică structura internă a celorlalte clase.

### Funcție `template`
- Am creat `afiseazaEvaluari<T>(jucatori, scoruri)` care parcurge o listă de jucători și scoruri de tip `T`, afișând evaluarea fiecăruia.
- A fost apelată concret în `main.cpp` pentru scoruri întregi.

### Design patterns (4 folosite):

#### Factory
- Clasa `AntrenorFactory` construiește `Antrenor*` pe baza unui string și stream.
- Logica din `main.cpp` este delegată clasei factory → cod curat și extensibil.

#### Singleton
- Clasa `Logger` este unică în aplicație, prin metoda statică `getInstance()`.
- Este folosită pentru logări în `main` la fiecare pas important (ex: echipă creată, fișiere încărcate etc.)

#### Prototype
- Implementat prin metoda virtuală `clone()` în `Antrenor`.
- Utilizat în `Echipa::adaugaAntrenor()` pentru a copia corect obiectele.

#### Command
- Am creat o interfață `Command` cu metoda `executa()`.
- Clasa `AfiseazaJucatoriCommand` execută comanda specifică, iar în `main` a fost apelată ca obiect logic.

---

## Clase implementate

### Clasa abstractă `Antrenor`
- Atribute: `nume`, `experienta`
- Funcții virtuale pure: `descriere()`, `clone()`, `getLimbiVorbite()`
- Metode comune: `getNume()`, `getExperienta()`
- Excepție: dacă experiența < 0

### Clase derivate din `Antrenor`
- `PreparatorFizic`: include atribute despre antrenamente și limbi vorbite
- `AnalistVideo`: detalii software, meciuri analizate, nivel analiză
- `PsihologSportiv`: consiliere sportivi, participare la antrenamente

### Clasa `Jucator`
- Atribute:
  - `nume`, `pozitie`, `numarTricou`, `nationalitate`, `limbiVorbite`, `esteCapitan`
  - `dataNasterii`, `dataIntrareClub`
  - `goluriMarcate`, `paseDecisive` (calculate din meciuri)
- Excepție: dacă `goluriMarcate` < 0
- Metode utile: `calculeazaVarsta()`, `aniInClub()`, `getNume()`, `getLimbiVorbite()`

### Clasa `Echipa`
- Atribute: `numeEchipa`, vectori de pointeri la `Jucator` și `Antrenor`, limba oficială (static)
- Funcții:
  - `adaugaAntrenor()`, `adaugaJucator()`
  - `compatibilitate()`
  - `numaraPreparatori()`, `numaraAnalisti()`, `numaraPsihologi()`
  - Acces: `getJucatori()`, `getNumeEchipa()`, `getLimbaOficiala()`

### Clasa `Meci`
- Atribute: `adversar`, vector de 11 jucători, goluri și pase înregistrate
- Actualizează statistici în jucători prin `Sezon`

### Clasa `Sezon`
- Generează automat 32 de meciuri
- Actualizează scorurile jucătorilor
- Rezumat afișat la finalul execuției

---

## Fișiere de intrare
- `antrenori.txt`: descrie fiecare antrenor, limbi, tip, etc.
- `jucatori.txt`: descrie fiecare jucător (nume, date, poziție, limbi, capitan)

---

## Exemple afișate în consolă
- Afișare listă antrenori și jucători
- Evaluare jucători folosind scoruri compuse (`goluri*3 + pase*2`)
- Statistici echipă (număr antrenori pe roluri)
- Compatibilitate antrenori cu limbi jucători
- Rezumat sezon: adversar + performanță pe meci
- Comenzi executabile: afișare jucători (Command)

---

## Bibliografie
- Codebeauty YouTube Channel: https://www.youtube.com/@CodeBeauty  
- GitHub mcmarius: https://github.com/mcmarius/poo/tree/master/tema-2  
- W3Schools C++: https://www.w3schools.com/cpp/  
- Pattern Command https://refactoring.guru/design-patterns/command/cpp/example
- Pattern Prototype https://refactoring.guru/design-patterns/prototype/cpp/example
