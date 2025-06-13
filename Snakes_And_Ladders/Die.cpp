/// @file Die.cpp
/// @author Adam T Koehler, PhD
/// @date May 27, 2025
/// @brief Die class function implementations.

#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Board/Player/Die Class/Die.h"

using namespace std;


Die::Die(){
    sides = {1,2,3,4,5,6};

}

int Die::roll(){
    int rollVal = sides.at(rand() % sides.size());
    allValues.push_back(rollVal);
    return rollVal;
}

void Die::addDieSide(int val){
    sides.push_back(val);
}

void Die::resetDie(){
    sides.clear();
    sides = {1,2,3,4,5,6};
}

double Die::getAverageRoll(){
    int total = 0;
    for (size_t i = 0; i < allValues.size();++i){
        total += allValues.at(i);
    }
    avg = static_cast<double>(total) / allValues.size();

    return avg;
}