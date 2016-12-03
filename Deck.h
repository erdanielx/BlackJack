#ifndef _DECK_H_
#define _DECK_H_
#include <iostream>
#include "card.h"

class Deck{
    protected:
        Card *cardArr;
        int siz;
    public:
        Deck();
        Deck(Card*,int);
        Deck(const Deck&);
        ~Deck();
        void addCard(const Card*);
        void printDeck();
        void delCard(Card&);
        Card* giveRandomCard();
};
class StandardDeck:public Deck{
    public:
        StandardDeck();
        StandardDeck(int);
        ~StandardDeck();
};
#endif
