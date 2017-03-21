//
// Created by luuk on 19-3-17.
//

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>

using namespace std;

#include "System.h"
#include "TestUtils.h"

class SystemDomainTest: public ::testing::Test {
protected:
    friend class System;

    System system;
    Tram tram;
    Station station;
};

TEST_F(SystemDomainTest, DefaultConstructor) {
    EXPECT_TRUE(system.properlyInitialized());
    EXPECT_TRUE(station.properlyInitialized());
    EXPECT_TRUE(tram.properlyInitialized());
}



class SystemOutputTests: public ::testing::Test {
protected:
    friend class System;

    System system;
    Station station;
    Tram tram;
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

    //Setting station variables
    station.setNaam("A");
    station.setVorige("A");
    station.setVolgende("A");
    station.setSpoor(10);
    //Adding station to system
    system.addStation(station.getNaam(), &station);

    //Setting tram variables
    tram.setLijnNr(10);
    tram.setZitplaatsen(55);
    tram.setSnelheid(60);
    tram.setBeginStation("A");
    tram.setHuidigStation("A");
    //Adding tram to system
    system.addTram(tram.getLijnNr(), &tram);

    //Creating output-string
    string testOutput = system.parserOutput();

    ofstream








}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

