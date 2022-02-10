//
// Created by void on 10.02.2022.
//

#ifndef ZESTAWB_PIRATEMAP_H
#define ZESTAWB_PIRATEMAP_H

#include <fstream>
#include <ostream>

using namespace std;

class PirateMap {
private:
    const string mapPath;
protected:
    fstream map;

    // Resets the map stream
    void resetMap();

public:
    virtual ~PirateMap();

    explicit PirateMap(const string &map);
    explicit PirateMap(PirateMap &map);

    friend ostream &operator<<(ostream &os, const PirateMap &map);
};


#endif //ZESTAWB_PIRATEMAP_H
