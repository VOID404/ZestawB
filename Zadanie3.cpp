//
// Created by marty on 2/8/2022.
//
using namespace std;

#include <fstream>
#include <iostream>
#include <vector>
#include "Zadanie3.h"
static vector<string> odczytaj(string nazwa) {
    fstream mapa;
    mapa.open(nazwa,ios::in);
    if (!mapa.good()) {
        cout << "Brak pliku" << endl;
        exit(0);
    }

    vector<string> odczyt;
    string linia;

    while (getline(mapa,linia)) {
        odczyt.push_back(linia);
    }
    mapa.close();

    return odczyt;
}