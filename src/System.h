//
// Created by uauser on 3/16/17.
//

#ifndef TRAM_NETWERK_SYSTEM_H
#define TRAM_NETWERK_SYSTEM_H

#include "Station.h"
#include "Tram.h"
#include <iostream>
#include <map>
#include "DesignByContract.h"

using namespace std;

class System {
private:
    map<string, Station *> stations;
    map<int, Tram *> trams;
    System* _initCheck;

public:
    System();

    bool properlyInitialized();

    map<string, Station*> getStations();

    map<int, Tram*> getTrams();

    string parserOutput();

    string verplaatsTram(int spoorNr, string stationsNaam);

    void addStation(string naam, Station* station);

    void addTram(int lijnNr, Tram* tram);

};

#endif //TRAM_NETWERK_SYSTEM_H
