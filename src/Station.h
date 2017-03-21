//
// Created by uauser on 3/2/17.
//

#ifndef XML_EX_STATION_H
#define XML_EX_STATION_H

#include <iostream>
#include "DesignByContract.h"

using namespace std;

class Station{
private:
    Station* _initCheck;
    string naam;
    string vorige;
    string volgende;
    int spoor;

public:
    Station();

    string getNaam();

    string getVorige();

    string getVolgende();

    int getSpoor();

    void setNaam(string naam);

    void setVorige(string vorige);

    void setVolgende(string volgende);

    void setSpoor(int spoor);

    bool properlyInitialized();

};


#endif //XML_EX_STATION_H
