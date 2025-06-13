#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "../Util/Utility_Functions.h"

using namespace std;


class Options{
    public:
        int getNumPlayers();
        int getNumBots();
        int getSeed();

        void setNumPlayers(int players);
        void setNumBots(int bots);
        void setSeed(int seed);

        void initOpt(const char* fileName);
        void optStore();
        void operator=(const Options& otherOpt);
    
    private:
        int numPlayers;
        int numBots;
        int seed;
};

void howToPlay();
int stringToSeed(const string& s);
void displayOptions(Options& currOpt);
void options(Options& currOpt, const Options& defaultOpt);
void printTitle();
void displayMenu();
bool menuSelect(Options& currOpt, const Options& defaultOpt);