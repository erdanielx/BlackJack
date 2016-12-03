#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include "Hand.h"
#include "Account.h"

class Hand;
class Account;
class Player{
    private:
        std::string name;
        Hand *hnd;
        Account *ac;
        double be;
    public:
        Player();
        Player(const Player&);
        Player(std::string);
        Player(std::string,Hand*,Account*);
        ~Player();
        void setName(std::string);
        std::string getName();
        Account* getAccount();
        Hand* getHand();
        void bet(double);
        void doubleBet();
        void blackjack();
        void win();
        friend std::ostream& operator<<(std::ostream&, const Player&);
};
#endif
