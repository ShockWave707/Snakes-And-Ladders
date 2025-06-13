// header file for Player Class
#pragma once
#include <vector>
#include "Die Class/Die.h"
#include "../../Util/Utility_Functions.h"
#include <chrono>
#include <thread>

using namespace std;

class Player {
    private:
        bool isPlayer; // false if computer controlled, true if player controlled
        int numPlayer; // number player 0-3 for both CPU and players
        int currLocation; // space the player is currently on
        int prevLocation; // space the player was previously on
        int turnNum; // number in turn order
        char token; // letter that represents player on the board
        vector<char> playerTokens;
        Die die;

    public:
        //constructors
        Player();
        Player(bool isPlayer, int numPlayer);    
        
        // getters
        bool getIsPlayer() const;
        int getNumPlayer() const;
        int getCurrLocation() const;
        int getPrevLocation() const;
        int getTurnNum() const;
        char getToken() const;
        Die getDie() const;
        
        // setters
        void setIsPlayer(bool isPlayer);
        void setNumPlayer(int numPlayer);
        void setCurrLocation(int currLocation);
        void setPrevLocation(int prevLocation);
        void setTurnNum(int turnNum);
        void setToken(char token);
        void setDie(Die die);

        
        // functionality
        int takeTurn();
        double averageRoll();
        void addToDie(int side);
        void resetDie();

        // Display who's turn it is
        void player1();
        void player2();
        void player3();
        void player4();
        void bot1();
        void bot2();
        void bot3();
        void bot4();
        void printTurn();
};