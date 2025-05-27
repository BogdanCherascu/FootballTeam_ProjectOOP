cmake_minimum_required(VERSION 3.30)
project(ProiectPOO2)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProiectPOO2 main.cpp
        jucator.h
        antrenor.h
        echipa.h
        jucator.cpp
        antrenor.cpp
        echipa.cpp
        PreparatorFizic.cpp
        PreparatorFizic.h
        AnalistVideo.cpp
        AnalistVideo.h
        PsihologSportiv.cpp
        PsihologSportiv.h
        ExceptieNivelExperienta.h
        ExceptieGoluriNegative.h
        ExceptieEchipaGoala.h
        Meci.cpp
        Meci.h
        Sezon.cpp
        Sezon.h
        Evaluare.h
        AfisareEval.h
        AntrenorFactory.cpp
        AntrenorFactory.h
        Logger.cpp
        Logger.h
        Command.h
        AfiseazaJucatoriCommand.h)
