
#ifndef ANTRENORFACTORY_H
#define ANTRENORFACTORY_H

#include "Antrenor.h"
#include "PreparatorFizic.h"
#include "AnalistVideo.h"
#include "PsihologSportiv.h"
#include <string>
#include <vector>
#include <sstream>

class AntrenorFactory {
public:
    static Antrenor* creeaza(const std::string& tip, std::istream& in);
};


#endif //ANTRENORFACTORY_H
