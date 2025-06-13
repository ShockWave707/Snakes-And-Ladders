using namespace std;

#include "Menu/menu.h"

int stringToSeed(const string& s){
    string newS;
    int result = 0;

    //convert each character to an int
    for(size_t i = 0; i < s.size(); i++){
        result += s.at(i);
    }

    return result;
}

//==========================OPTIONS===========================

void displayOptions(Options& currOpt){
    //clear terminal
    printf("\33[H\33[2J");
    fflush(stdout);

    //open file
    string line;
    ifstream file;
    file.open("Menu/options.txt");

    if(!file.is_open()){
        cerr << "File unable to open -> EXIT 3" << endl;
        exit(3);
    }

    //read and output title
    while(getline(file, line)){
        cout << line << endl;
        //delay for dramatic effect
        this_thread::sleep_for(chrono::milliseconds(20));
    }

    //display current options
    cout << "Current Players: " << currOpt.getNumPlayers() << endl
         << "Current Bots: " << currOpt.getNumBots() << endl
         << "Current Seed: " << currOpt.getSeed() << endl;
    
    //close file
    file.close();
}

void options(Options& currOpt, const Options& defaultOpt){
    char userInput;
    int userInput2;
    string userInput3;
    vector<string> funnyFile;

    while(1){
        displayOptions(currOpt);
        cin >> userInput;
        
        switch(userInput){
            case 's':
            case 'S':
                displayOptions(currOpt);
                cout << "Please enter a new seed: ";
                cin >> userInput3;
                
                cout << stringToSeed(userInput3) << endl;
                currOpt.setSeed(stringToSeed(userInput3));
                srand(currOpt.getSeed());
                break;

            case 'p':
            case 'P':
                displayOptions(currOpt);
                cout << "Please enter a new player count (0-4): ";
                cin >> userInput2;
                cout << endl;

                while(userInput2 > 4 || userInput2 < 0){
                    displayOptions(currOpt);
                    cout << "Please enter a valid player count (0-4): ";
                    cin >> userInput2;
                }
                currOpt.setNumPlayers(userInput2);
                break;
            
            case 'b':
            case 'B':
                displayOptions(currOpt);
                cout << "Please enter a new bot count (0-4): ";
                cin >> userInput2;
                cout << endl;

                while(userInput2 > 4 || userInput2 < 0){
                    displayOptions(currOpt);
                    cout << "Please enter a valid bot count (0-4): ";
                    cin >> userInput2;
                }
                currOpt.setNumBots(userInput2);
                break;

            case 'r':
            case 'R':
                displayOptions(currOpt);
                cout << endl << "Resetting settings to default settings..." << endl;
                currOpt = defaultOpt;
                this_thread::sleep_for(chrono::milliseconds(2500));
                break;

            case 'm':
            case 'M':
                if((currOpt.getNumBots() + currOpt.getNumPlayers()) < 2){
                    if(currOpt.getNumBots() == 1){
                        funnyFile = readFile("Board/Loser.txt");
                        for(size_t i = 0; i < funnyFile.size(); i++){
                            cout << funnyFile.at(i) << endl;
                        }
                        this_thread::sleep_for(chrono::milliseconds(2500));
                    }
                    else if(currOpt.getNumPlayers() == 1){
                        funnyFile = readFile("Board/Winner.txt");
                        for(size_t i = 0; i < funnyFile.size(); i++){
                            cout << funnyFile.at(i) << endl;
                        }
                        this_thread::sleep_for(chrono::milliseconds(2500));
                    }
                    cout << "Please have a total of at least 2 players and bots." << endl;
                    this_thread::sleep_for(chrono::milliseconds(2500));
                }
                else{
                    return;
                }
                break;
            
            default:
                cout << "Please enter a valid input when prompted." << endl;
                this_thread::sleep_for(chrono::milliseconds(2500));
                break;
        };
    }
}

///////////////////////GET AND SET/////////////////////

int Options::getNumPlayers(){
    return numPlayers;
}

int Options::getNumBots(){
    return numBots;
}

int Options::getSeed(){
    return seed;
}

void Options::setNumPlayers(int players){
    numPlayers = players;
}

void Options::setNumBots(int bots){
    numBots = bots;
}

void Options::setSeed(int seed){
    this->seed = seed;
}

/////////////////////////END OF GET AND SET///////////////////////////////

//initialize Options Class
void Options::initOpt(const char* fileName){
    //open file
    string line;
    ifstream file;
    file.open(fileName);
    if(!file.is_open()){
        cerr << "File unable to open -> EXIT 5" << endl;
        exit(5);
    }

    //read from file and store in Options class object
    file >> line;
    numPlayers = stoi(line);
    file >> line;
    numBots = stoi(line);
    
    //close file
    file.close();
}

//store current options on exit
void Options::optStore(){
    //open file and erase all current data
    string line;
    ofstream file;
    file.open("Menu/settingsCurrent.txt", ios::trunc);
    if(!file.is_open()){
        cerr << "File unable to open -> EXIT 6" << endl;
        exit(6);
    }

    //write to file and store options
    file << to_string(numPlayers) << endl << to_string(numBots) << endl;
    
    //close file
    file.close();
}

void Options::operator=(const Options& otherOpt){
    this->numPlayers = otherOpt.numPlayers;
    this->numBots = otherOpt.numBots;
    this->seed = otherOpt.seed;
}

//======================================END OF OPTIONS==================================

void howToPlay(){
    //clear terminal
    printf("\33[H\33[2J");
    fflush(stdout);

    //open file
    string line;
    ifstream file;
    file.open("Menu/HowToPlay.txt");
    if(!file.is_open()){
        cerr << "File unable to open -> EXIT 1" << endl;
        exit(1);
    }

    //read and output title
    while(getline(file, line)){
        cout << line << endl;
        //delay for dramatic effect
        this_thread::sleep_for(chrono::milliseconds(20));
    }
    
    //close file & wait for user input
    file.close();
    cin.ignore();
    getchar();
}

void printTitle(){
    //clear terminal
    printf("\33[H\33[2J");
    fflush(stdout);

    //open file
    string line;
    ifstream file;
    file.open("Menu/title.txt");
    if(!file.is_open()){
        cerr << "File unable to open -> EXIT 8" << endl;
        exit(8);
    }

    //read and output title
    while(getline(file, line)){
        cout << line << endl;
        //delay for dramatic effect
        this_thread::sleep_for(chrono::milliseconds(150));
    }
    
    //close file & wait for user input
    file.close();
    getchar();
}

void displayMenu(){
    //clear terminal
    printf("\033[40m");
    printf("\033[97m");
    printf("\33[H\33[2J");
    fflush(stdout);

    //open file
    string line;
    ifstream file;
    file.open("Menu/menu.txt");

    if(!file.is_open()){
        cerr << "File unable to open -> EXIT 2" << endl;
        exit(2);
    }

    //read and output title
    while(getline(file, line)){
        cout << line << endl;
        //delay for dramatic effect
        this_thread::sleep_for(chrono::milliseconds(20));
    }
    
    //close file
    file.close();
}

//Menu selection before the game (return true to start game, return false to exit)
bool menuSelect(Options& currOpt, const Options& defaultOpt){
    char userInput = 'a';

    while(1){
        displayMenu();
        cin >> userInput;
        cout << endl;

        switch(userInput){
            case 's':
            case 'S':
                return true;
            
            case 'h':
            case 'H':
                howToPlay();
                break;
            
            case 'o':
            case 'O':
                options(currOpt, defaultOpt);
                break;
            
            case 'q':
            case 'Q':
                return false;
                break;
            
            default:
                cout << endl << "Please input a valid character below" << endl;
                this_thread::sleep_for(chrono::milliseconds(1500));
        };
    }

}