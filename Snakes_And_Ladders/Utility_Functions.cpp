// .cpp file for utility functions

#include "Util/Utility_Functions.h"

// function to read a file line by line and return it as a vector of strings
vector<string> readFile(string fileName){
    string line;
    vector<string> fileLines;
    ifstream file;

    file.open(fileName);
    if(!file.is_open()){
        cerr << "File unable to open -> EXIT 4" << endl;
        exit(4);
    }
        //read file to vector

    
    while(getline(file, line)){
        fileLines.push_back(line);        
    }

    file.close();   
    return fileLines;
}
