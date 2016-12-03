#ifndef _GAMECARRIER_H_
#define _GAMECARRIER_H_
#include <iostream>
#include "card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Account.h"

using namespace std;

class GameCarrier{
    private:
        Player *pl;
        Hand *hnd;
        Account *acc;
        int siz;
        int sizpl;
        int sizhnd;
        int sizacc;
    public:
        GameCarrier();
        GameCarrier(Player*,Hand*,Account*,int);
        GameCarrier(int);
        ~GameCarrier();
        void addHand(Hand*);
        void addAccount(Account*);
        void addPlayer(Player*);
        void addInstance(Player*,Account*,Hand*);
        void remHand(int);
        void remAccount(int);
        void remPlayer(int);
        void remInstance(int);
        void printPlayers();
        void printAccounts();
        void printHands();
        void startGame();
        Player* getPlayer(int);
};
#endif
