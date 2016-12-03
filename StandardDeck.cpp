#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Deck.h"

StandardDeck::StandardDeck(){
    srand(time(NULL));
    std::string suits[4] = {"Spades","Hearts","Diamonds","Clubs"};
    std::string shows[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    int i;
    int j;
    int w=0;
    cardArr = new Card[52];
    for(i=0;i<13;i++){
        for(j=0;j<4;j++){
            cardArr[w] = Card(suits[j],shows[i]);
            w++;
        }
    }
}
StandardDeck::StandardDeck(int a){
    srand(time(NULL));
    std::string suits[4] = {"Spades","Hearts","Diamonds","Clubs"};
    std::string shows[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    cardArr = new Card[a*52];
    int i;
    int j;
    int w=0;
    int x;
    for(x=0;x<a;x++){
        for(i=0;i<13;i++){
            for(j=0;j<4;j++){
                cardArr[w] = Card(suits[j],shows[i]);
                w++;
            }
        }
    }
}
StandardDeck::~StandardDeck(){
    delete []cardArr;
}
