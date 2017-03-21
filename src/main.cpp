//
// Created by luuk on 19-3-17.
//

#include "Parser.h"
#include <iostream>


using namespace std;

int main(){
    Parser* parser;
    System* system = parser->XmlParser("InputFiles/XML_Test.xml");
    cout << system->parserOutput();
}

