#ifndef AFISAREEVAL_H
#define AFISAREEVAL_H

#include <vector>
#include <iostream>

template <typename T>
void afiseazaEvaluare(const std::vector<Jucator*>& jucatori, const std::vector<T>& scoruri) {
    for (size_t i = 0; i < jucatori.size() && i < scoruri.size(); ++i) {
        std::cout << "Evaluare pentru " << jucatori[i]->getNume()
                  << " = " << scoruri[i] << "\n";
    }
}


#endif
