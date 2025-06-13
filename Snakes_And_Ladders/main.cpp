#include "Menu/menu.h"
#include "Board/Board.h"
#include "Animations/animation.h"
#include <climits>



using namespace std;

int main() 
{
    Animations dice;

    Options currOpt;
    Options defaultOpt;

    //initialize options
    currOpt.initOpt("Menu/settingsCurrent.txt");
    defaultOpt.initOpt("Menu/settingsDefault.txt");
    
    random_device r;
    
    static uniform_int_distribution<int> eng(0,INT_MAX);

    currOpt.setSeed(eng(r));
    defaultOpt.setSeed(currOpt.getSeed());

    //initialize seed
    srand(currOpt.getSeed());

    //show title and make (COLOR HERE)
    printf("\033[107m");
    printf("\033[30m");
    fflush(stdout);
    printTitle();


    while(menuSelect(currOpt, defaultOpt)){
        // game start

        //Initialize & fill vector of players
        vector<Player> players;
        for (int i = 0; i < currOpt.getNumPlayers();++i){
            players.push_back(Player(1,i));
        }
        for(int i = 0; i < currOpt.getNumBots();++i){
            players.push_back(Player(0,i));
        }
         
        //Initialize Board
        Board board("Board/Board_0.txt", players);
        board.drawBoard(players);
        bool winner = false;
        size_t playerTurn = 0;
        string userInput;



        while(!winner){

            players.at(playerTurn).printTurn();
            board.drawBoard(players);

            if(players.at(playerTurn).getIsPlayer()){

                cout << endl << "Please enter a valid action \"roll\" or \"rage quit\"" << endl;
                getline(cin, userInput);

                 //wait for player to roll die, type roll
                while(userInput != "roll" && userInput != "rage quit"){
                    getline(cin, userInput);
                }
                if(userInput == "rage quit"){
                    cout << "PLAYER COULDNT TAKE IT ANYMORE, RETURNING TO MENU" << endl;
                    this_thread::sleep_for(chrono::milliseconds(2500));
                    break;
                }
            }

            //animate die roll
            dice.printRoll(players.at(playerTurn).takeTurn());
            board.updateBoard(players.at(playerTurn));

            //update board visual after moving player token
            players.at(playerTurn).printTurn();
            board.drawBoard(players);
            this_thread::sleep_for(chrono::milliseconds(2500));

            if(players.at(playerTurn).getCurrLocation() >= 100){
                winner = true;
                //end annimation for winner
                vector<string> winFile = readFile("Board/Winner.txt");
                for(size_t i = 0; i < winFile.size(); i++){
                    cout << winFile.at(i) << endl;
                }
                
                if(players.at(playerTurn).getIsPlayer()){
                    cout << "Player " << players.at(playerTurn).getToken() << " Wins!" << endl;
                }
                else{
                    cout << "Bot " << players.at(playerTurn).getToken() << " Wins!" << endl;
                }
                this_thread::sleep_for(chrono::milliseconds(5000));
            } 
            else{
                playerTurn += 1;

                if (playerTurn == players.size()){
                    playerTurn = 0;
                }

            }
                
        }
        
    }   
    currOpt.optStore();
    //game exit
    
    printf("\033[0m");
    
    return 0;
}