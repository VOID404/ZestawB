#include <iostream>
#include <fstream>
#include <vector>

#ifdef _WIN32
#define mapPath "C:\\Users\\marty\\Desktop\\mapa.txt"
#endif

#ifdef linux
#define mapPath "./mapa.txt"
#endif

using namespace std;

int main() {
    fstream mapa;
    mapa.open(mapPath, fstream::in);

    if (!mapa.good()) {
        cout << "Brak mapy w " << mapPath << endl;
        return 0;
    }

    vector<string> linie;
    string linia;

    while (getline(mapa, linia)) {
        linie.push_back(linia);
    }

    mapa.close();

    int najdluzszy = 0;
    int sumMapa = 0;

    for (int i = 0; i < linie.size(); ++i) {
        if (linie[i].length() > najdluzszy) {
            najdluzszy = linie[i].length();
        }
        sumMapa += linie[i].length();
    }

    double wynik = (sumMapa * 100) / (najdluzszy * linie.size());

    if (wynik >= 80) {
        cout << "ok" << endl;
    } else {
        cout << "nok" << endl;
    }

}

