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

    int najdluzszy = 0;
    int wysokosc = 0;
    int sumMapa = 0;

    while (getline(mapa, linia)) {
        int dlugosc = linia.length();
        najdluzszy = max(dlugosc, najdluzszy);
        sumMapa += dlugosc;
        ++wysokosc;
    }
    mapa.close();

    double wynik = (sumMapa * 100) / (najdluzszy * wysokosc);
    cout << (wynik >= 80 ? "ok" : "nok") << endl;
}

