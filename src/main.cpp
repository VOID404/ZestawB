#include <iostream>
#include <fstream>
#include <vector>

#include "Zadanie2.h"
#include "Zadanie4.h"

#ifdef _WIN32
#define mapPath "C:\\Users\\marty\\Desktop\\mapa.txt"
#endif

#ifdef linux
#define mapPath "./mapa.txt"
#endif

using namespace std;

int main() {
    PirateMap map(mapPath);
    Zadanie2(map).solve();
    Zadanie4(map).solve();
    return 0;
}
