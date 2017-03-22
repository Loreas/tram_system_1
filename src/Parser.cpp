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



bool Parser::XmlParser(string inputFile) {
    bool output = true;
    cout << "======================" << endl;
    cout << "Starting XML Parser..." << endl;
    cout << "======================" << endl << endl;
    TiXmlDocument doc;
    const char *file = inputFile.c_str();
    if (!doc.LoadFile(file)) {
        return false;
    }

    TiXmlElement* root = doc.FirstChildElement();
    if (root == NULL) {
        cerr << "Failed to load file: No root element." << endl;
        doc.Clear();
        return false;
    }
    System* system = new System;

    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL;
         elem = elem->NextSiblingElement()) {
        string elemName = elem->Value();

        if (elemName == "station") {
            cout << "Creating new Station:" << endl;
            Station* station = new Station;

            for (TiXmlElement *insideElem = elem->FirstChildElement(); insideElem != NULL;
                 insideElem = insideElem->NextSiblingElement()) {
                string elemName = insideElem->Value();

                if (elemName == "naam") {
                    if (getElement(insideElem) != "") {
                        system->addStation(getElement(insideElem), station);
                        cout << "   Setting Station name..." << endl;
                        station->setNaam(getElement(insideElem));
                    } else {
                        output = false;
                        delete[] station;

                    }
                }
                if (elemName == "volgende") {
                    if (getElement(insideElem) != "") {
                        cout << "   Setting next Station..." << endl;
                        station->setVolgende((getElement(insideElem)));
                    } else {
                        output = false;
                    }
                }
                if (elemName == "vorige") {
                    if (getElement(insideElem) != "") {
                        cout << "   Setting previous Station..." << endl;
                        station->setVorige(getElement(insideElem));
                    } else {
                        output = false;
                    }
                }
                if (elemName == "spoor") {
                    if(getElement(insideElem) != "") {
                        cout << "   Setting Station track..." << endl;
                        station->setSpoor(stoi(getElement(insideElem)));
                    }
                    else{
                        output = false;
                    }
                }
            }
        }
        else if (elemName == "tram") {
            Tram* tram = new Tram;
            cout << "Creating new Tram:" << endl;

            for (TiXmlElement *insideElem = elem->FirstChildElement(); insideElem != NULL;
                 insideElem = insideElem->NextSiblingElement()) {
                 string elemName = insideElem->Value();


                if (elemName == "lijnNr") {
                    if (getElement(insideElem) != "") {
                        system->addTram(stoi(getElement(insideElem)), tram);
                        cout << "   Setting Tram Line Nr..." << endl;
                        tram->setLijnNr(stoi(getElement(insideElem)));
                    } else {
                        output = false;
                        delete[] tram;

                    }
                }
                if (elemName == "zitplaatsen") {
                    cout << "   Setting Tram seats..." << endl;
                    if (getElement(insideElem) != "") {
                        tram->setZitplaatsen(stoi(getElement(insideElem)));
                    } else {
                        output = false;

                    }
                }

                if (elemName == "snelheid") {
                    cout << "   Setting Tram speed..." << endl;
                    tram->setSnelheid(stoi(getElement(insideElem)));
                }

                if (elemName == "beginStation") {
                    cout << "   Setting Starting Station..." << endl;
                    tram->setBeginStation(getElement(insideElem));
                    tram->setHuidigStation(getElement(insideElem));
                    cout << "   Setting Current Station..." << endl << endl;

                    }
            }
    }
}
    Parser::setSystem(system);

    cout << "===================" << endl;
    cout << "XML Parser finished" << endl;
    cout << "===================" << endl << endl;
    doc.Clear();
    return output;
}

System *Parser::getSystem() const {
    return system;
}

void Parser::setSystem(System *system) {
    Parser::system = system;
}
