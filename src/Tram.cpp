//
// Created by uauser on 3/2/17.
//

#include "Tram.h"

Tram::Tram() {
    _initCheck = this;
}

bool Tram::properlyInitialized() {
    return _initCheck == this;
}

int Tram::getLijnNr() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getLijnNr.");
    return lijnNr;
}

int Tram::getZitplaatsen() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getZitplaatsen.");
    return zitplaatsen;
}

int Tram::getSnelheid() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getSnelheid.");
    return snelheid;
}

string Tram::getBeginStation() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getBeginStation.");
    return beginStation;
}

string Tram::getHuidigStation() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getHuidigStation.");
    return huidigStation;
}

void Tram::setLijnNr(int lijnNr) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setLijnNr.");
    ENSURE(lijnNr > 0,"No negative line numbers allowed");
    Tram::lijnNr = lijnNr;
}

void Tram::setZitplaatsen(int zitplaatsen) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setZitplaatsen.");
    ENSURE(zitplaatsen > 0,"No negative seats allowed");
    Tram::zitplaatsen = zitplaatsen;
}

void Tram::setSnelheid(int snelheid) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setSnelheid.");
    ENSURE(snelheid > 0,"No negative speed allowed");
    Tram::snelheid = snelheid;
}

void Tram::setBeginStation(string beginStation) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setBeginStation.");
    ENSURE(beginStation != "","No empty string for Starting Station allowed");
    Tram::beginStation = beginStation;
}

void Tram::setHuidigStation(string huidigStation) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setHuidigStation.");
    ENSURE(huidigStation != "","No empty string for Current Station allowed");
    Tram::huidigStation = huidigStation;
}


