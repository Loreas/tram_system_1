//
// Created by uauser on 3/2/17.
//

#ifndef XML_EX_TRAM_H
#define XML_EX_TRAM_H

#include <iostream>
#include "DesignByContract.h"
using namespace std;


class Tram {
private:
    int lijnNr;
    int zitplaatsen;
    int snelheid;
    string beginStation;
    string huidigStation;
    Tram* _initCheck;

public:
    Tram();

    int getLijnNr();

    int getZitplaatsen();

    int getSnelheid();

    string getBeginStation();

    void setLijnNr(int lijnNr);

    void setZitplaatsen(int zitplaatsen);

    void setSnelheid(int snelheid);

    void setBeginStation(string beginStation);

    string getHuidigStation();

    void setHuidigStation(string huidigStaton);

    bool properlyInitialized();
};


#endif //XML_EX_TRAM_H
