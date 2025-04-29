#ifndef ANTRENOR_H
#define ANTRENOR_H

#include <string>
#include <iostream>
#include <vector>

class Antrenor {
protected:
    std::string nume;
    int experienta;

public:
    Antrenor(const std::string& nume, int experienta);
    virtual ~Antrenor();

    virtual void descriere() const = 0; // funcție virtuală pură
    virtual Antrenor* clone() const = 0; // constructor virtual (copy polimorfic)


    // Funcție comună pentru toate clasele
    int getExperienta() const;
    virtual std::vector<std::string> getLimbiVorbite() const = 0;
    std::string getNume() const;

};

#endif // ANTRENOR_H
