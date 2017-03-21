//
// Created by uauser on 3/2/17.
//

#include "Station.h"

Station::Station() {
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
    Station::naam = naam;
}

void Station::setVorige(string vorige) {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling setVorige.");
    Station::vorige = vorige;
}

void Station::setVolgende(string volgende) {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling setVolgende.");
    Station::volgende = volgende;
}

void Station::setSpoor(int spoor) {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling setSpoor.");
    Station::spoor = spoor;
}


