#pragma once

/// @file Die.h
/// @author Adam T Koehler, PhD
/// @date May 27, 2025
/// @brief Die class declaration.

#include <string>
#include <vector>

using namespace std;

class Die 
{
    private:
        vector<int> allValues;
        double avg;
        vector<int> sides;
    public:

        Die();
        int roll();
        void addDieSide(int val);
        void resetDie();
        double getAverageRoll();

};