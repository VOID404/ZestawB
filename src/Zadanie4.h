//
// Created by void on 10.02.2022.
//

#ifndef ZESTAWB_ZADANIE4_H
#define ZESTAWB_ZADANIE4_H

#include "PirateMap.h"
#include "Zadanie.h"

class Zadanie4 : PirateMap, Zadanie {
    using PirateMap::PirateMap;
public:
    explicit Zadanie4(PirateMap &map) : PirateMap(map) {};

    void solve() override;
};


#endif //ZESTAWB_ZADANIE4_H
