#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Deck.h"


Deck::Deck(){
    srand(time(NULL));
    cardArr = new Card[1];
    siz = 0;
}
Deck::Deck(Card* c,int x){
    srand(time(NULL));
    siz = x;
    cardArr = new Card[x];
    int i;
    for(i=0;i<x;i++){
        cardArr[i] = c[i];
    }
}
Deck::Deck(const Deck& d){
    srand(time(NULL));
    cardArr = new Card[d.siz];
    int i;
    for(i=0;i<siz;i++){
        cardArr[i] = d.cardArr[i];
    }
}
Deck::~Deck(){
    delete []cardArr;
}
void Deck::addCard(const Card* c){
    Card cardAr2[siz];
    int i;
    for(i=0;i<siz;i++){
        cardAr2[i] = cardArr[i];
    }
    delete []cardArr;
    siz++;
    cardArr = new Card[siz];
    for(i=0;i<(siz-1);i++){
        cardArr[i] = cardAr2[i];
    }
    cardArr[i]=*c;
}
void Deck::printDeck(){
    int i;
    for(i=0;i<siz;i++){
        std::cout << cardArr[i];
        std::cout << std::endl;
    }
}
void Deck::delCard(Card& c){
    int i;
    for(i=0;i<siz;i++){
        if(cardArr[i].getSuit()==c.getSuit() && cardArr[i].getShow()==c.getShow()){
            do{
                cardArr[i] = cardArr[i+1];
                i++;
            }while(i<siz);
            siz--;
            break;
        }
    }
}
Card* Deck::giveRandomCard(){
    int x = rand()%siz;
    Card *w = &cardArr[x];
    delCard(cardArr[x]);
    return w;
}
