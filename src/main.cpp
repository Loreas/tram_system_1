//
// Created by luuk on 19-3-17.
//

#include "Parser.h"
#include <iostream>


using namespace std;

int main(){

    Parser parser;
    parser.XmlParser("InputFiles/XML_Test.xml");
    System* system = parser.getSystem();
    system->properlyparsed();
    cout << system->parserOutput();
    cout << system->ronde_rijden();
}

