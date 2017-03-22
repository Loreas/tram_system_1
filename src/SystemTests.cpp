//
// Created by luuk on 19-3-17.
//

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>

using namespace std;

#include "Parser.h"
#include "TestUtils.h"

class SystemDomainTest: public ::testing::Test {
protected:
    friend class System;

    System system;
};

TEST_F(SystemDomainTest, DefaultConstructor) {
    Station* testStation = new Station();
    Tram* testTram = new Tram();
    EXPECT_TRUE(system.properlyInitialized());
    EXPECT_TRUE(testStation->properlyInitialized());
    EXPECT_TRUE(testTram->properlyInitialized());

}

TEST_F(SystemDomainTest, HappyDay) {
    Station station1;
    Station station2;

    station1.setNaam("A");
    station1.setVorige("B");
    station1.setVolgende("B");
    station1.setSpoor(10);

    station2.setNaam("B");
    station2.setVorige("A");
    station2.setVolgende("A");
    station2.setSpoor(10);

    system.addStation(station1.getNaam(), &station1);
    system.addStation(station2.getNaam(), &station2);

    Tram* tram = new Tram();

    tram->setLijnNr(10);
    tram->setZitplaatsen(30);
    tram->setSnelheid(75);
    tram->setBeginStation("A");
    tram->setHuidigStation("A");

    system.addTram(tram->getLijnNr(), tram);

    EXPECT_EQ("A", station1.getNaam());
    EXPECT_EQ("B", station2.getNaam());
    EXPECT_EQ(10, tram->getLijnNr());

    string output = system.ronde_rijden();

    string expected = "Rondje rijden...";
    expected += "\n";
    expected += "Tram 10 reed van station A naar station B";
    expected += "\n";
    expected += "Tram 10 reed van station B naar station A";
    expected += "\n";
    expected += "\n";

    EXPECT_EQ(output, expected);
}


TEST_F(SystemDomainTest, SetNameViolation) {
    Station testStation;
    EXPECT_DEATH(testStation.setNaam(""), "No empty string for Station Name allowed");
}

TEST_F(SystemDomainTest, SetVorigeViolation) {
    Station testStation;
    EXPECT_DEATH(testStation.setVorige(""), "No empty string for previous Station allowed");
}

TEST_F(SystemDomainTest, SetVolgendeViolation) {
    Station testStation;
    EXPECT_DEATH(testStation.setVolgende(""), "No empty string for next Station allowed");
}

TEST_F(SystemDomainTest, SetSpoorViolation) {
    Station testStation;
    EXPECT_DEATH(testStation.setSpoor(-5), "No negative Track Number allowed");
}

TEST_F(SystemDomainTest, SetLijnNrViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setLijnNr(-60), "No negative line numbers allowed");
}

TEST_F(SystemDomainTest, SetZitplaatsenViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setZitplaatsen(-15), "No negative seats allowed");
}

TEST_F(SystemDomainTest, SetSpeedViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setSnelheid(-20), "No negative speed allowed");
}

TEST_F(SystemDomainTest, SetBeginstationViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setBeginStation(""), "No empty string for Starting Station allowed");
}

TEST_F(SystemDomainTest, SetHuidigstationViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setHuidigStation(""), "No empty string for Current Station allowed");
}

class SystemInputTests: public ::testing::Test {
protected:
    friend class Parser;

    Parser parser;
};

TEST_F(SystemInputTests, InputFileTests) {
    ASSERT_TRUE(DirectoryExists("testInput"));

    ofstream inputFile;

    inputFile.open("testInput/testInput1.xml");
    inputFile << "<SYSTEM>" << endl
              << "\t<station>" << endl
              << "\t\t<naam>" << "A" << endl
              << "\t\t</naam>" << endl
              << "\t</station>" << endl
              << "</SYSTEM>";
    inputFile.close();

    bool importResult = parser.XmlParser("testInput/testInput1.xml");

    EXPECT_TRUE(importResult);
}

TEST_F(SystemInputTests, CircularTest) {
    ofstream inputFile;

    inputFile.open("testInput/testInput2.xml");
    inputFile << "<SYSTEM>" << endl
              << "\t<station>" << endl
              << "\t\t<naam>" << "A"
              << "</naam>" << endl
              << "\t\t<vorige>" << "B"
              << "</vorige>" << endl
              << "\t\t<volgende>" << "C"
              << "</volgende>" << endl
              << "\t</station>" << endl
              << "</SYSTEM>";
    inputFile.close();

    parser.XmlParser("testInput/testInput2.xml");

    EXPECT_FALSE(parser.getSystem()->Valid_circuit());
}

////TEST_F(SystemInputTests, EmptyStationName){
////    parser.XmlParser("testInput/StationsNaam.xml");
////    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "Name of Station can't be empty.");
////}
//
//TEST_F(SystemInputTests, EmptyPrevStation){
//    parser.XmlParser("testInput/VorigStation.xml");
//    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "Name of previous Station can't be empty.");
//}
//
//TEST_F(SystemInputTests, EmptyNextStation){
//    parser.XmlParser("testInput/VolgendStation.xml");
//    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "Name of next Station can't be empty.");
//}
//
//TEST_F(SystemInputTests, EmptyStationTrack){
//    parser.XmlParser("testInput/StationSpoor.xml");
//    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "Number of track can't be negative.");
//}
//
//TEST_F(SystemInputTests, EmptyLineNr){
//    parser.XmlParser("testInput/TramLijnNr.xml");
//    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "Line Number can't be negative.");
//}
//
//TEST_F(SystemInputTests, EmptySeats){
//    parser.XmlParser("testInput/TramZitplaatsen.xml");
//    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "Amount of seats can't be negative.");
//}
//
//TEST_F(SystemInputTests, EmptySpeed){
//    parser.XmlParser("testInput/TramSnelheid.xml");
//    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "Speed can't be negative.");
//}
//
//TEST_F(SystemInputTests, EmptyStartingStation){
//    parser.XmlParser("testInput/BeginStationTram.xml");
//    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "Name of Startstation can't be empty.");
//}

class SystemOutputTests: public ::testing::Test {
protected:
    friend class System;

    System system;
};

TEST_F(SystemOutputTests, OutputFileTests){
    // Designed based on TicTacToeOutputTests:
    // Copyright: Project Software Engineering - BA1 informatica - Serge Demeyer -
    // University of Antwerp
    ASSERT_TRUE(DirectoryExists("testOutput"));

    ofstream outputFile;
    outputFile.open("testOutput/outputFile1.txt");
    outputFile.close();
    outputFile.open("testOutput/outputFile2.txt");
    outputFile.close();

    EXPECT_TRUE(FileExists("testOutput/outputFile1.txt"));
    EXPECT_TRUE(FileIsEmpty("testOutput/outputFile1.txt"));
    EXPECT_TRUE(FileExists("testOutput/outputFile2.txt"));
    EXPECT_TRUE(FileIsEmpty("testOutput/outputFile1.txt"));

    EXPECT_TRUE(FileCompare("testOutput/outputFile1.txt", "testOutput/outputFile2.txt"));
    EXPECT_TRUE(FileCompare("testOutput/outputFile2.txt", "testOutput/outputFile1.txt"));

    Station station;
    station.setNaam("A");
    station.setVorige("A");
    station.setVolgende("A");
    station.setSpoor(10);
    //Adding station to system
    system.addStation(station.getNaam(), &station);

    //Setting tram variables
    Tram tram;
    tram.setLijnNr(10);
    tram.setZitplaatsen(55);
    tram.setSnelheid(60);
    tram.setBeginStation("A");
    tram.setHuidigStation("A");
    //Adding tram to system
    system.addTram(tram.getLijnNr(), &tram);

    //Creating output-string
    string outputString = system.parserOutput();

    ofstream testOutput;
    testOutput.open("testOutput/outputFile1.txt");
    testOutput << outputString;
    testOutput.close();

    ofstream testOutput2;
    testOutput2.open("testOutput/outputFile2.txt");
    testOutput2 << "Station A" << endl
                << "<- Station A" << endl
                << "-> Station A" << endl
                << "Spoor 10, 55 zitplaatsen" << endl << endl;
    testOutput2.close();
    SetUp();
    EXPECT_TRUE(FileCompare("testOutput/outputFile1.txt", "testOutput/outputFile2.txt"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

