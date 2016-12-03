#include <iostream>
#include "card.h"


Card::Card(){
    valA = 0;
    valB = 0;
    suit = "spades";
    show = "0";
    calculateValues();
}
Card::Card(const Card& c){
    this->valA = c.valA;
    this->valB = c.valB;
    this->suit = c.suit;
    this->show = c.show;
    calculateValues();
}
Card::Card(std::string suit, std::string show){
    this->suit = suit;
    this->show = show;
    calculateValues();
}
Card::~Card(){
}
void Card::calculateValues(){
    if(show=="0"){
        valA = valB = 0;
    }
    else if(show=="A"){
        valA = 1;
        valB = 11;
    }
    else if(show=="2"){
        valA= valB = 2;
    }
    else if(show=="3"){
        valA = valB = 3;
    }
    else if(show=="4"){
        valA = valB = 4;
    }
    else if(show=="5"){
        valA = valB = 5;
    }
    else if(show=="6"){
        valA = valB = 6;
    }
    else if(show=="7"){
        valA = valB = 7;
    }
    else if(show=="8"){
        valA = valB = 8;
    }
    else if(show=="9"){
        valA = valB = 9;
    }
    else if(show=="10" || show=="J" || show=="Q" || show=="K"){
        valA = valB = 10;
    }
}
int Card::getA(){
    return valA;
}
int Card::getB(){
    return valB;
}
std::string Card::getSuit(){
    return suit;
}
std::string Card::getShow(){
    return show;
}
std::ostream& operator<<(std::ostream& out,const Card& c){
    out << c.show << " of " << c.suit;
    return out;
}
