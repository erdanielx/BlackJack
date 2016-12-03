#include <iostream>
#include "Hand.h"

Hand::Hand():Deck(){
    computeSums();
}
Hand::Hand(const Hand& h):Deck(h){
    this->owner = h.owner;
    computeSums();
}
Hand::Hand(Card* c, int n, Player* p):Deck(c,n){
    this->owner = p;
    computeSums();
}
Hand::~Hand(){
}
int Hand::getSumA(){
    return sumA;
}
int Hand::getSumB(){
    return sumB;
}
void Hand::computeSumForA(){
    int i;
    int sum=0;
    for(i=0;i<siz;i++){
        sum+=cardArr[i].getA();
    }
    sumA = sum;
}
void Hand::computeSumForB(){
    int j=0;
    int i;
    for(i=0;i<siz;i++){
        if(cardArr[i].getShow()=="A"){
            j++;
        }
    }
    int exclude[j];
    int x=0;
    int sum=0;
    for(i=0;i<siz;i++){
        if(cardArr[i].getB()==11){
            exclude[x] =  i;
            x++;
        }
    }
    for(i=0;i<siz;i++){
        for(x=0;x<j;x++){
            if(exclude[x]==i){
                continue;
            }
            else{
                sum+=cardArr[i].getB();
            }
        }
    }
    for(i=0;i<siz;i++){
        for(x=0;x<j;x++){
            if(exclude[x]==i){
                if((sum+11)<=21){
                    sum+=11;
                }
                else{
                    sum+=1;
                }
            }
            else{
                sum+=cardArr[i].getB();
            }
        }
    }
    sumB = sum;
}
void Hand::computeSums(){
    computeSumForA();
    computeSumForB();
}
bool Hand::inGame(){
    bool x;
    computeSums();
    if(sumB<=21 || sumA<=21){
        x = true;
    }
    else{
        x = false;
    }
    return x;
}
void Hand::printValues(){
    computeSums();
    if(sumA==sumB){
        std::cout << "You sum " << sumA;
        if(inGame()){
            std::cout << ". You are still in the game!";
        }
        else{
            std::cout << ". You passed 21, try again next time.";
        }
    }
    else if(sumB>21) {
        std::cout << "You sum " << sumA;
        if(inGame()){
            std::cout << ". You are still in the game!";
        }
        else{
            std::cout << ". You passed 21, try again next time.";
        }
    }
    else if(sumB<=21) {
        std::cout << "You sum " << sumA << ", or" << sumB;
        if(inGame()){
            std::cout << ". You are still in the game!";
        }
        else{
            std::cout << ". You passed 21, try again next time.";
        }
    }
}
