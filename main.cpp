#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

struct Pozycja {
    int x;
    int y;
};

static double oblicz(Pozycja a, Pozycja b) {
    return sqrt(pow(a.x-b.x,2)+(a.y-b.y,2));
}

static Pozycja szukaj(std::fstream mapa) {
    mapa.open("mapa.txt", std::ios::in);
    if (!mapa.good()) {
        std::cout << "Brak mapy" << std::endl;
        exit(0);
    }

    std::vector<std::string> linie;

    std::string linia = "";
    while (getline(mapa,linia)){
        linie.push_back(linia);
    }

    mapa.close();

    Pozycja joe;
    std::vector<Pozycja> skarby;

    for (int i; i < linie.size(); ++i) {
        for (int j =0; j < linie[i].length(); ++j) {
            if (linie[i].at(j)=='B') {
                joe.x = i + 1;
                joe.y = j + 1;
            } else if (linie[i].at(j) == '$'){
                Pozycja skarb;
                skarb.x = i+1;
                skarb.y = j+1;
                skarby.push_back(skarb);
            }
        }
    }

    Pozycja najbliższy;
    najbliższy.x = linie[1].length();
    najbliższy.y = linie.size();
    double odległosc = oblicz(joe,najbliższy);

    for (int i = 0; i < skarby.size(); ++i) {
        double temp = oblicz(joe,skarby[i]);
        if (temp < odległosc) {
            odległosc = temp;
            najbliższy.x = skarby[i].x;
            najbliższy.y = skarby[i].y;
        }
    }

    std::cout << "Odległość od aktualnej pozycji B (" << joe.x << "," << joe.y << ") do najbliższego skarbu $ (" << najbliższy.x << "," << najbliższy.y << ") to:" << odległosc << std::endl;
    return  najbliższy;
}

int main() {
    std::fstream mapa;
    mapa.open("mapa.txt", std::ios::in);
    if (!mapa.good()) {
        std::cout << "Brak mapy" << std::endl;
        exit(0);
    }

    std::vector<std::string> linie;

    std::string linia = "";
    while (getline(mapa,linia)){
        linie.push_back(linia);
    }

    mapa.close();

    Pozycja joe;
    std::vector<Pozycja> skarby;

    for (int i; i < linie.size(); ++i) {
        for (int j =0; j < linie[i].length(); ++j) {
            if (linie[i].at(j)=='B') {
                joe.x = i + 1;
                joe.y = j + 1;
            } else if (linie[i].at(j) == '$'){
                Pozycja skarb;
                skarb.x = i+1;
                skarb.y = j+1;
                skarby.push_back(skarb);
            }
        }
    }

    Pozycja najbliższy;
    najbliższy.x = linie[1].length();
    najbliższy.y = linie.size();
    double odległosc = oblicz(joe,najbliższy);

    for (int i = 0; i < skarby.size(); ++i) {
        double temp = oblicz(joe,skarby[i]);
        if (temp < odległosc) {
            odległosc = temp;
            najbliższy.x = skarby[i].x;
            najbliższy.y = skarby[i].y;
        }
    }

    std::cout << "Odległość od aktualnej pozycji B (" << joe.x << "," << joe.y << ") do najbliższego skarbu $ (" << najbliższy.x << "," << najbliższy.y << ") to:" << odległosc << std::endl;

    return 0;
}

