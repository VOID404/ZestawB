//
// Created by void on 10.02.2022.
//

#include "PirateMap.h"

#include <stdexcept>
#include <iostream>

using namespace std;

PirateMap::~PirateMap() {
    this->map.close();
}

PirateMap::PirateMap(const string &map) : map(map, fstream::in), mapPath(map) {
    if (!this->map.good()) {
        throw invalid_argument("Brak mapy w \"" + map + "\"");
    }
}

void PirateMap::resetMap() {
    this->map.clear();
    this->map.seekg(0, ios::beg);
}

ostream &operator<<(ostream &os, const PirateMap &map) {
    os << map.map.rdbuf();
    return os;
}

PirateMap::PirateMap(PirateMap &map) : PirateMap(map.mapPath) {}
