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
    Tram::lijnNr = lijnNr;
}

void Tram::setZitplaatsen(int zitplaatsen) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setZitplaatsen.");
    Tram::zitplaatsen = zitplaatsen;
}

void Tram::setSnelheid(int snelheid) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setSnelheid.");
    Tram::snelheid = snelheid;
}

void Tram::setBeginStation(string beginStation) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setBeginStation.");
    Tram::beginStation = beginStation;
}

void Tram::setHuidigStation(string huidigStation) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setHuidigStation.");
    Tram::huidigStation = huidigStation;
}


