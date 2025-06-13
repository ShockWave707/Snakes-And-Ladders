// .cpp file for Player class
#include "Board/Player/Player.h"


using namespace std;
//constructors
Player::Player(){
    playerTokens = {'!','@','#','$','%','^','&','*'};
    isPlayer = false;
    numPlayer = -1;
    currLocation = 1;
    prevLocation = 1;
    turnNum = -1;
    token = 'X';
    die = Die();
    
}

Player::Player(bool isPlayer, int numPlayer){
    this->isPlayer = isPlayer;
    this->numPlayer = numPlayer;
    playerTokens = {'!','@','#','$','%','^','&','*'};
    if(this-> isPlayer){
        turnNum = this->numPlayer;
        token = playerTokens.at(this->numPlayer);
    }
    else{
        turnNum = this->numPlayer + 4;
        token = playerTokens.at(this->numPlayer + 4);
    }
    
    currLocation = 1;
    prevLocation = 1;
    die = Die();

}

// getters
bool Player::getIsPlayer() const{return isPlayer;}
int Player::getNumPlayer() const{return numPlayer;}
int Player::getCurrLocation() const{return currLocation;}
int Player::getPrevLocation() const{return prevLocation;}
int Player::getTurnNum() const{return turnNum;}
char Player::getToken() const{return token;}
Die Player::getDie() const{return die;}

// setters
void Player::setIsPlayer(bool isPlayer){this->isPlayer = isPlayer;}
void Player::setNumPlayer(int numPlayer){this->numPlayer = numPlayer;}
void Player::setCurrLocation(int currLocation){this->currLocation = currLocation;}
void Player::setPrevLocation(int prevLocation){this->prevLocation = prevLocation;}
void Player::setTurnNum(int turnNum){this->turnNum = turnNum;}
void Player::setToken(char token){this->token = token;}
void Player::setDie(Die die){this->die = die;}

// functionality -> NEED TO CHECK FOR SNAKES AND LADDERS
int Player::takeTurn(){
    
    int dieRoll = die.roll();
    
    prevLocation = currLocation;
    currLocation = prevLocation + dieRoll;
    
    if (currLocation > 100){
        currLocation = 100;
    }
    return dieRoll;
}

// Display who's turn it is
void Player::printTurn(){
    printf("\033[107m");
    printf("\033[30m");
    fflush(stdout);
    
    if(isPlayer){
        switch(numPlayer){
            case 0:
                player1();
                break;
            
            case 1:
                player2();
                break;
            
            case 2:
                player3();
                break;

            case 3:
                player4();
                break;

            default:
                cerr << "Invalid Player Number" << endl;
                exit(7);
        };
    }
    else{
        switch(numPlayer){
            case 0:
                bot1();
                break;
            
            case 1:
                bot2();
                break;
            
            case 2:
                bot3();
                break;

            case 3:
                bot4();
                break;

            default:
                cerr << "Invalid Player Number" << endl;
                exit(7);
        };
    }
    
}

// read from file to display who's turn it is
void Player::player1(){
    vector<string> vec = readFile("Board/Player/Player1'sTurn.txt");
    
    for(size_t i = 0; i < vec.size(); i++){
        cout << vec.at(i) << endl;
    }
}

void Player::player2(){
    vector<string> vec = readFile("Board/Player/Player2'sTurn.txt");
    
    for(size_t i = 0; i < vec.size(); i++){
        cout << vec.at(i) << endl;
    }
}

void Player::player3(){
    vector<string> vec = readFile("Board/Player/Player3'sTurn.txt");
    
    for(size_t i = 0; i < vec.size(); i++){
        cout << vec.at(i) << endl;
    }
}

void Player::player4(){
    vector<string> vec = readFile("Board/Player/Player4'sTurn.txt");
    
    for(size_t i = 0; i < vec.size(); i++){
        cout << vec.at(i) << endl;
    }
}

void Player::bot1(){
    vector<string> vec = readFile("Board/Player/Bot1'sTurn.txt");
    
    for(size_t i = 0; i < vec.size(); i++){
        cout << vec.at(i) << endl;
    }
}

void Player::bot2(){
    vector<string> vec = readFile("Board/Player/Bot2'sTurn.txt");
    
    for(size_t i = 0; i < vec.size(); i++){
        cout << vec.at(i) << endl;
    }
}

void Player::bot3(){
    vector<string> vec = readFile("Board/Player/Bot3'sTurn.txt");
    
    for(size_t i = 0; i < vec.size(); i++){
        cout << vec.at(i) << endl;
    }
}

void Player::bot4(){
    vector<string> vec = readFile("Board/Player/Bot4'sTurn.txt");
    
    for(size_t i = 0; i < vec.size(); i++){
        cout << vec.at(i) << endl;
    }
}