//
// Created by Luuk van Sloun on 3/9/17.
//

#include "Parser.h"
#include <iostream>

using namespace std;

Parser::Parser() {}

string Parser::getElement(TiXmlElement* elem){
    TiXmlNode* e = elem->FirstChild();
    TiXmlText* text = e->ToText();
    if (text == NULL)
        return "";
    string t = text->Value();
    return t;
}

bool Parser::legalInput(string input){
    if(input == ""){
        return false;
    }

    return true;
}

System* Parser::XmlParser(string inputFile) {
    cout << "======================" << endl;
    cout << "Starting XML Parser..." << endl;
    cout << "======================" << endl << endl;
    TiXmlDocument doc;
    const char *file = inputFile.c_str();
    if (!doc.LoadFile(file)) {
        return NULL;
    }

    TiXmlElement* root = doc.FirstChildElement();
    if (root == NULL) {
        cerr << "Failed to load file: No root element." << endl;
        doc.Clear();
        return NULL;
    }

    System* system = new System();
    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL;
         elem = elem->NextSiblingElement()) {
        string elemName = elem->Value();

        if (elemName == "station") {
            cout << "Creating new Station:" << endl;
            Station *station = new Station();
            ENSURE(station->properlyInitialized(),
                   "Constructor must be initialized properly.");

            for (TiXmlElement *insideElem = elem->FirstChildElement(); insideElem != NULL;
                insideElem = insideElem->NextSiblingElement()) {
                string elemName = insideElem->Value();
                if (elemName == "naam") {
                    cout << "   Setting Station name..." << endl;
                    REQUIRE(legalInput(getElement(insideElem)), "Name of Station can't be empty.");
                    station->setNaam(getElement(insideElem));
                    system->addStation(getElement(insideElem), station);
                }
                if (elemName == "volgende") {
                    cout << "   Setting next Station..." << endl;
                    REQUIRE(legalInput(getElement(insideElem)), "Name of next Station can't be empty.");
                    station->setVolgende((getElement(insideElem)));
                }
                if (elemName == "vorige") {
                    cout << "   Setting previous Station..." << endl;
                    REQUIRE(legalInput(getElement(insideElem)), "Name of previous Station can't be empty.");
                    station->setVorige(getElement(insideElem));
                }
                if (elemName == "spoor") {
                    cout << "   Setting Station track..." << endl;
                    REQUIRE(legalInput(getElement(insideElem)), "Name of track can't be empty.");
                      station->setSpoor(stoi(getElement(insideElem)));
                 }
            }
        }
            else if (elemName == "tram") {
                Tram *tram = new Tram();
                cout << "Creating new Tram:" << endl;
                ENSURE(tram->properlyInitialized(),
                       "Constructor must be initialized properly.");

                for (TiXmlElement *insideElem = elem->FirstChildElement(); insideElem != NULL;
                     insideElem = insideElem->NextSiblingElement()) {
                     string elemName = insideElem->Value();


                    if (elemName == "lijnNr") {
                        cout << "   Setting Tram Line Number..." << endl;
                        REQUIRE(legalInput(getElement(insideElem)), "Line Number can't be empty.");
                        tram->setLijnNr(stoi(getElement(insideElem)));
                        system->addTram(stoi(getElement(insideElem)), tram);
                    }
                    if (elemName == "zitplaatsen") {
                        cout << "   Setting Tram seats..." << endl;
                        REQUIRE(legalInput(getElement(insideElem)), "Amount of seats can't be none.");
                        tram->setZitplaatsen(stoi(getElement(insideElem)));
                    }

                    if (elemName == "snelheid") {
                        cout << "   Setting Tram speed..." << endl;
                        REQUIRE(legalInput(getElement(insideElem)), "Speed can't be none.");
                        tram->setSnelheid(stoi(getElement(insideElem)));
                    }

                    if (elemName == "beginStation") {
                        cout << "   Setting Starting Station..." << endl << endl;
                        REQUIRE(legalInput(getElement(insideElem)), "Name of Startstation can't be empty.");
                        tram->setBeginStation(getElement(insideElem));
                        tram->setHuidigStation(getElement(insideElem));

                        }
                }
        }
    }
    cout << "===================" << endl;
    cout << "XML Parser finished" << endl;
    cout << "===================" << endl << endl;
    doc.Clear();
    return system;
}
