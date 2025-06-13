#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include "../Util/Utility_Functions.h"

using namespace std;

class Animations{
    public:
        Animations();
        void animate();
        void printRoll(int);
        void Roll1();
        void Roll2();
        void Roll3();
        void Roll4();
        void Roll5();
        void Roll6();
    private:
        vector<string> roll1;
        vector<string> roll2;
        vector<string> roll3;
        vector<string> roll4;
        vector<string> roll5;
        vector<string> roll6;
        vector<string> frame1;
        vector<string> frame2;
};