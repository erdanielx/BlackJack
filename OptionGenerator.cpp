#include <iostream>
#include "OptionGenerator.h"

using namespace std;

OptionGenerator::OptionGenerator(){
}
OptionGenerator::~OptionGenerator(){
}
int OptionGenerator::go(int x){
    int y=0;
    int m;
    if(x==0){
        cout << "\nWelcome! Input Number of players: " << endl;
        y=0;
    }
    else if(x==1){
        cout << "\n1. View List\n2. Continue\n";
        cin >> m;
        if(m==1){
            y=2;
        }
        if(m==2){
            y=0;
        }
    }
    else if(x==2){
        cout << "\n1. Add Player\n2. Remove Player\n3. Continue\n";
        cin >> m;
        if(m==1){
            y=3;
        }
        else if(m==2){
            y=4;
        }
        else if(m==3){
            y=0;
        }
    }
    else if(x==3){
        cout << "How should the money be distributed?\n1. Custom\n2. All the same\n";
        cin >> m;
        if(m==1){
            y=5;
        }
        if(m==2){
            y=6;
        }
    }
    return y;
}
