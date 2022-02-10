//
// Created by void on 10.02.2022.
//

#include "Zadanie2.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

void Zadanie2::solve() {
    szukaj();

    auto dist = distance(skarb, joe);

    cout << "Odległość od aktualnej pozycji B " << joe
         << " do najbliższego skarbu $ " << skarb
         << " to: " << dist << endl;
}

double Zadanie2::distance(Zadanie2::Point a, Zadanie2::Point b) {
    return sqrt(pow(a.x - b.x, 2) + (a.y - b.y, 2));

}

void Zadanie2::szukaj() {
    std::vector<std::string> lines;

    std::string line = "";
    while (getline(this->map, line)) {
        lines.push_back(line);
    }

    std::vector<Point> skarby;

    for (int i; i < lines.size(); ++i) {
        for (int j = 0; j < lines[i].length(); ++j) {
            if (lines[i].at(j) == 'B') {
                joe.x = i + 1;
                joe.y = j + 1;
            } else if (lines[i].at(j) == '$') {
                Point skarb;
                skarb.x = i + 1;
                skarb.y = j + 1;
                skarby.push_back(skarb);
            }
        }
    }

    Point najbliższy;
    najbliższy.x = lines[1].length();
    najbliższy.y = lines.size();
    double odległosc = distance(joe, najbliższy);

    for (int i = 0; i < skarby.size(); ++i) {
        double temp = distance(joe, skarby[i]);
        if (temp < odległosc) {
            odległosc = temp;
            najbliższy.x = skarby[i].x;
            najbliższy.y = skarby[i].y;
        }
    }

    skarb = najbliższy;
}

ostream &operator<<(ostream &os, const Zadanie2::Point &point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
