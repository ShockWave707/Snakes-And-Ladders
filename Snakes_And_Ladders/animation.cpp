using namespace std;

#include "Animations/animation.h"

Animations::Animations(){
    roll1 = readFile("Animations/DieRoll1.txt");
    roll2 = readFile("Animations/DieRoll2.txt");
    roll3 = readFile("Animations/DieRoll3.txt");
    roll4 = readFile("Animations/DieRoll4.txt");
    roll5 = readFile("Animations/DieRoll5.txt");
    roll6 = readFile("Animations/DieRoll6.txt");
    frame1 = readFile("Animations/Die Roll frame 1.txt");
    frame2 = readFile("Animations/Die Roll frame 2.txt");
}

void Animations::animate(){
    string line;

    for(int j = 0; j < 3; j++){
        printf("\33[H\33[2J");
        fflush(stdout);
        for(size_t i = 0; i < frame1.size(); i++){
            line = frame1.at(i);
            cout << line << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(400));
        
        printf("\33[H\33[2J");
        fflush(stdout);
        for(size_t i = 0; i < frame2.size(); i++){
            line = frame2.at(i);
            cout << line << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(400));
    }
    printf("\33[H\33[2J");
    fflush(stdout);
}

void Animations::printRoll(int dieVal){
    switch(dieVal){
        case 1:
            Roll1();
            break;
        
        case 2:
            Roll2();
            break;

        case 3:
            Roll3();
            break;

        case 4:
            Roll4();
            break;

        case 5:
            Roll5();
            break;
        
        case 6:
            Roll6();
            break;
        
        default:
            cerr << "Invalid Die Roll -> EXIT 9" << endl;
            exit(9);
    };
}

void Animations::Roll1(){
    animate();
    string line;
    for(size_t i = 0; i < roll1.size(); i++){
        line = roll1.at(i);
        cout << line << endl;
    }
    getchar();
}

void Animations::Roll2(){
    animate();
    string line;
    for(size_t i = 0; i < roll2.size(); i++){
        line = roll2.at(i);
        cout << line << endl;
    }
    getchar();
}

void Animations::Roll3(){
    animate();
    string line;
    for(size_t i = 0; i < roll3.size(); i++){
        line = roll3.at(i);
        cout << line << endl;
    }
    getchar();
}

void Animations::Roll4(){
    animate();
    string line;
    for(size_t i = 0; i < roll4.size(); i++){
        line = roll4.at(i);
        cout << line << endl;
    }
    getchar();
}

void Animations::Roll5(){
    animate();
    string line;
    for(size_t i = 0; i < roll5.size(); i++){
        line = roll5.at(i);
        cout << line << endl;
    }
    getchar();
}

void Animations::Roll6(){
    animate();
    string line;
    for(size_t i = 0; i < roll6.size(); i++){
        line = roll6.at(i);
        cout << line << endl;
    }
    getchar();
}