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

void System::addStation(string naam, Station* station) {
    System::stations[naam]=station;
}

void System::addTram(int lijnNr, Tram* tram){
    trams[lijnNr]=tram;
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
    }
    return output;
}

string System::verplaatsTram(int spoorNr, string stationsNaam){
    string volgende = System::getStations().find(stationsNaam)->second->getVolgende();
    System::getTrams().find(spoorNr)->second->setHuidigStation(volgende);
    string output = "Tram " + to_string(spoorNr) + " reed van station " + stationsNaam
                                                    + " naar station " + volgende;
    return output;
}
