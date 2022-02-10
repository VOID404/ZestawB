//
// Created by void on 10.02.2022.
//

#ifndef ZESTAWB_ZADANIE2_H
#define ZESTAWB_ZADANIE2_H

#include "PirateMap.h"
#include "Zadanie.h"

class Zadanie2 : PirateMap, Zadanie {
    using PirateMap::PirateMap;
protected:
    struct Point {
        int x;
        int y;
        friend ostream &operator<<(ostream &os, const Point &point);
    };

private:
    Point joe;
    Point skarb;

    double distance(Point a, Point b);
    void szukaj();
    friend ostream &operator<<(ostream &os, const Point &point);

public:
    explicit Zadanie2(PirateMap &map) : PirateMap(map) {};

    void solve() override;
};


#endif //ZESTAWB_ZADANIE2_H
