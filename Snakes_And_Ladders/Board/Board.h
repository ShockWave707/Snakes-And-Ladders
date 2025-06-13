//header file for Board class
#pragma once

#include <vector>
#include <string>
#include "Player/Player.h"
#include "../Color/color.h"

using namespace std;

class Board {
    private:
        vector<int> spaces; //index is start of snake/ladder, contents is ending location, contents is 0 if index empty space, -1 if index is an end space
        vector<string> lines; // lines of the board to be read in from default board file
        string filename; // board file to read in at setup

    public:
        //constructors
        Board();
        Board(string filename, vector<Player> &players);

        void readBoard(); // called by constructors, reads board file into lines vector
        void fillSpaces(); // called by constructors, populates spaces vector with snake/ladder locations
        void updateBoard(Player& player);
        void drawBoard(vector<Player>& players); 

        // gets called by updateBoard, checks player location for snake/ladder
        void checkTransit(Player& player); 

};