//
// Created by void on 10.02.2022.
//

#include "Zadanie4.h"
#include <iostream>

using namespace std;

void Zadanie4::solve() {
    string line;

    int longest = 0;
    int height = 0;
    int sum = 0;

    while (getline(this->map, line)) {
        int len = line.length();
        longest = max(len, longest);
        sum += len;
        ++height;
    }

    double ratio = (sum * 100) / (longest * height);
    cout << (ratio >= 80 ? "ok" : "nok") << endl;
}
