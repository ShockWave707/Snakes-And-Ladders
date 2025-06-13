#include "Color/color.h"

const char* RED = "\033[41m";
const char* GREEN = "\033[42m";
const char* YELLOW = "\033[103m";
const char* BLUE = "\033[104m";
const char* MAGENTA = "\033[45m";
const char* CYAN = "\033[106m";
const char* GRAY = "\033[100m";
const char* PINK = "\033[105m";
const char* RESET = "\033[107m";

void printPlayer(const char &token){
    switch(token){
        case '!':
            //p1 color
            printf("%s",RED);
            printf("\033[97m");
            cout <<"!"; 
            printf("\033[30m");
            printf("%s",RESET);
            break;
        case '@':
            //p2 color
            printf("%s",GREEN);
            cout <<"@"; 
            printf("%s",RESET);
            break;
        case '#':
            //p3 color
            printf("%s",YELLOW);
            cout <<"#"; 
            printf("%s",RESET);
            break;
        case '$':
            //p4 color
            printf("%s",BLUE);
            cout <<"$"; 
            printf("%s",RESET);
            break;
        case '%':
            //b1 color
            printf("%s",MAGENTA);
            printf("\033[97m");
            cout <<"%"; 
            printf("\033[30m");
            printf("%s",RESET);
            break;
        case '^':
            //b2 color
            printf("%s",CYAN);
            cout <<"^"; 
            printf("%s",RESET);
            break;
        case '&':
            //b3 color
            printf("%s",GRAY);
            printf("\033[97m");
            cout <<"&"; 
            printf("\033[30m");
            printf("%s",RESET);
            break;
        case '*':
            //b4 color
            printf("%s",PINK);
            cout <<"*"; 
            printf("%s",RESET);
            break;

        default:
            cout<< " ";
            break;
    };

}