//
// Created by Loreas Clonen on 3/9/17.
//

#include "System.h"
#include <memory>

using namespace std;

System::System() {
    _initCheck = this;
}

bool System::properlyInitialized() {
    return _initCheck == this;
}

map<string, Station *> System::getStations() {
    return stations;
}

map<int, Tram *> System::getTrams() {
    return trams;
}

void System::addStation(string naam, Station* station, bool fault) {
    if(fault) {
        System::stations[naam] = station;
    }
    else{
        System::stations[stations.end()->first] = station;
    }
}

void System::addTram(int lijnNr, Tram* tram, bool fault){
    if(fault) {
        System::trams[lijnNr] = tram;
    }
    else{
        System::trams[trams.end()->first] = tram;
    }
}


string System::parserOutput(){
    string output;
    for(auto const i : stations){
        output += "Station " + i.second->getNaam() + "\n";
        output += "<- Station " + i.second->getVorige() + "\n";
        output += "-> Station " + i.second->getVolgende() + "\n";
        output += "Spoor " + to_string(i.second->getSpoor()) + ", ";
        output += to_string(trams.find(i.second->getSpoor())->second->getZitplaatsen()) + " zitplaatsen";
        output += "\n";
        output += "\n";
    }
    return output;
}
string System::verplaatsTram(Tram* tram){
    string stationsNaam = tram->getHuidigStation();
    string volgende = System::getStations().find(stationsNaam)->second->getVolgende();
    tram->setHuidigStation(volgende);
    string output = "Tram " + to_string(tram->getLijnNr()) + " reed van station " + stationsNaam
                    + " naar station " + volgende+ "\n";
    return output;
}

bool System::legalInput(string input){
    if(input == ""){
        return false;
    }

    return true;
}


bool System::Valid_circuit() {
    for (auto const &it : stations) {
        Station *prev_station = stations.find(it.second->getVorige())->second;
        if(prev_station == stations.end()->second){
            return false;
        }
        Station *prev_next_station = stations.find(prev_station->getVolgende())->second;

        if(prev_next_station != it.second){
            return false;
        }
    }
    return true;
}

void System::properlyparsed() {

    for (auto const &it : stations) {
        ENSURE(it.second->properlyInitialized(),
               "Constructor must be initialized properly.");
        REQUIRE(legalInput(it.second->getNaam()), "Name of Station can't be empty.");
        REQUIRE(legalInput(it.second->getVolgende()), "Name of next Station can't be empty.");
        REQUIRE(legalInput(it.second->getVorige()), "Name of previous Station can't be empty.");
        REQUIRE(legalInput(to_string(it.second->getSpoor())), "Name of track can't be empty.");

    }
    for (auto const &it : trams) {
        ENSURE(it.second->properlyInitialized(),
               "Constructor must be initialized properly.");
        REQUIRE(legalInput(to_string(it.second->getLijnNr())), "Line Number can't be empty.");
        REQUIRE(legalInput(to_string(it.second->getZitplaatsen())), "Amount of seats can't be none.");
        REQUIRE(legalInput(to_string(it.second->getSnelheid())), "Speed can't be none.");
        REQUIRE(legalInput(it.second->getBeginStation()), "Name of Startstation can't be empty.");
    }
    ENSURE(System::Valid_circuit(), "Circuit is not valid.");
}


string System::ronde_rijden() {
    string output = "Rondje rijden...";
    output += "\n";
    for (int i = 0; i < stations.size(); i++) {
        for (auto const &j : trams) {
            output += System::verplaatsTram(j.second);
        }
    }
    output += "\n";
    return output;
}
