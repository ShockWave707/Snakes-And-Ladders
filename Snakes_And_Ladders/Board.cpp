// .cpp file for Board class
#include <cctype>
#include <string>
#include <vector>


#include "Board/Board.h"
#include "Util/Utility_Functions.h"


using namespace std;

Board::Board(){

    filename = "Board/Board.txt";
    readBoard();

    //fill spaces vector
    for (int i = 0; i < 101;++i){spaces.push_back(0);}
    fillSpaces();
    
}

Board::Board(string filename, vector<Player> &players){
    this->filename = filename;
    readBoard();
    
    //fill spaces vector
    for (int i = 0; i < 101;++i) {spaces.push_back(0);}
    fillSpaces();
    for (size_t i = 0; i< players.size();++i){
        updateBoard(players.at(i));
    }

}

void Board::readBoard(){
    //read file in
    vector<string> file = readFile(filename);
    //save file in reverse order so bottom of the board is at the front of the vector
    for(int i = (file.size()-1); i >= 0; --i){
        lines.push_back(file.at(i));
    }
}

void Board::fillSpaces(){
    //hard code for Board_0 snake/ladder starts
    if (filename == "Board/Board_0.txt"){
        spaces.at(2) = 38;
        spaces.at(4) = 14;
        spaces.at(9) = 31;
        spaces.at(16) = 6;
        spaces.at(21) = 42;
        spaces.at(28) = 84;
        spaces.at(36) = 44;
        spaces.at(47) = 26;
        spaces.at(49) = 11;
        spaces.at(51) = 67;
        spaces.at(56) = 54;
        spaces.at(62) = 19;
        spaces.at(64) = 60;
        spaces.at(71) = 91;
        spaces.at(80) = 100;
        spaces.at(87) = 24;
        spaces.at(93) = 73;
        spaces.at(95) = 75;
        spaces.at(98) = 78;  
     
    }    
    //puts -1 at spaces with snake/ladder end
    for (size_t i = 1; i<spaces.size();++i){
            if(spaces.at(i) > 0){
                spaces.at(spaces.at(i)) = -1;
            }
        }
}


void Board::updateBoard(Player& player){
    // updates board variables based on player turn

    //checks if player landed on a space with snake/ladder, changes currLocation if needed
    checkTransit(player);

    int oldCol,newCol;
    int oldRow = 1 + player.getIsPlayer() + 3 * ((player.getPrevLocation() - 1) / 10);
    int newRow = 1 + player.getIsPlayer() + 3 * ((player.getCurrLocation() - 1) / 10);
    
    //"I think" this works. need to actually test this 
    if(((player.getPrevLocation() -1 )/ 10) % 2 == 0){
        oldCol = 3 + player.getNumPlayer() + 7 * ((player.getPrevLocation() - 1) % 10);
    }
    else{
        oldCol = 66 + player.getNumPlayer() - 7 * ((player.getPrevLocation() - 1) % 10) ;
    }

    if (((player.getCurrLocation() -1) / 10) % 2 == 0){
        newCol = 3 + player.getNumPlayer() + 7 * ((player.getCurrLocation() - 1) % 10);
    }
    else{
        newCol = 66 + player.getNumPlayer() - 7 * ((player.getCurrLocation() - 1) % 10);
    }

    lines.at(oldRow).at(oldCol) = ' ';
    lines.at(newRow).at(newCol) = player.getToken();

}

void Board::drawBoard(vector<Player>& players){
    // outputs board to terminal
    vector<char> tokens;
    bool found;
    for(size_t x = 0; x < players.size();++x){
        tokens.push_back(players.at(x).getToken());
    }
    
    //outputs lines in reverse order so the last line is on the top
    for (int i = (lines.size() - 1); i >= 0; --i){
        for (size_t j = 0; j < lines.at(i).size(); ++j){
            found = false;
            for(size_t y = 0; y < tokens.size();++y){
                if(lines.at(i).at(j) == tokens.at(y)){
                    found = true;
                    printPlayer(tokens.at(y));
                    break;
                }
            }
            if (!found){
                cout << lines.at(i).at(j);
            }
        }
        cout << endl; 
    }
}

void Board::checkTransit(Player& player){
    if (spaces.at(player.getCurrLocation()) > 0){
        player.setCurrLocation(spaces.at(player.getCurrLocation()));
    }
}
