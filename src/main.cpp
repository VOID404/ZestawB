#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;


int main() {
    fstream mapa;
    mapa.open("C:\\Users\\marty\\Desktop\\mapa.txt", ios::in);

    if(!mapa.good()) {
        cout << "Brak mapy" << endl;
        return 0;
    }

    vector<string> linie;
    string linia;

    while(getline(mapa,linia)) {
        linie.push_back(linia);
    }

    mapa.close();

    int najdluzszy =0;
    int sumMapa = 0;

    for (int i = 0; i<linie.size(); ++i) {
        if (linie[i].length()>najdluzszy) {
            najdluzszy = linie[i].length();
        }
        sumMapa += linie[i].length();
    }

    double wynik = (sumMapa*100)/(najdluzszy*linie.size());

    if (wynik >= 80) {
        cout << "ok" << endl;
    } else {
        cout << "nok" << endl;
    }

}

