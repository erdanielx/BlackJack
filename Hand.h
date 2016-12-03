#ifndef _HAND_H_
#define _HAND_H_
#include <iostream>
#include "Deck.h"
#include "Player.h"

class Player;
class Hand:public Deck{
    private:
        Player *owner;
        int sumA;
        int sumB;
    public:
        Hand();
        Hand(const Hand&);
        Hand(Card*,int, Player*);
        ~Hand();
        void computeSumForA();
        void computeSumForB();
        void computeSums();
        int getSumA();
        int getSumB();
        bool inGame();
        void printValues();
};
#endif
