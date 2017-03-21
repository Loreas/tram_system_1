//
// Created by luuk on 19-3-17.
//

#ifndef TRAM_NETWERK_PARSER_H
#define TRAM_NETWERK_PARSER_H

#include "tinyxml.h"
#include <iostream>
#include "Station.h"
#include "Tram.h"
#include "System.h"
#include "DesignByContract.h"

using namespace std;

class Parser {
private:
    System* system;
public:
    Parser();

    System *getSystem() const;

    void setSystem(System *system);

    string getElement(TiXmlElement *elem);

    bool legalInput(string input);

    bool XmlParser(string inputFile);
};
#endif //TRAM_NETWERK_PARSER_H
