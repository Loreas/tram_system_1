//
// Created by uauser on 3/2/17.
//

#include "Station.h"

Station::Station() {
    Station::naam = "";
    Station::vorige = "";
    Station::volgende = "";
    Station::spoor = -1;
    _initCheck = this;
}

bool Station::properlyInitialized() {
    return _initCheck == this;
}

string Station::getNaam() {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling getNaam.");
    return naam;
}

string Station::getVorige() {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling getVorige.");
    return vorige;
}

string Station::getVolgende() {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling getVolgende.");
    return volgende;
}

int Station::getSpoor() {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling getSpoor.");
    return spoor;
}

void Station::setNaam(string naam) {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling setNaam.");
    ENSURE(naam != "","No empty string for Station Name allowed");
    Station::naam = naam;
}

void Station::setVorige(string vorige) {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling setVorige.");
    ENSURE(vorige != "","No empty string for previous Station allowed");
    Station::vorige = vorige;
}

void Station::setVolgende(string volgende) {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling setVolgende.");
    ENSURE(volgende != "","No empty string for next Station allowed");
    Station::volgende = volgende;
}

void Station::setSpoor(int spoor) {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling setSpoor.");
    ENSURE(spoor > 0 , "No negative Track Number allowed");
    Station::spoor = spoor;
}


