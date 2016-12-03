#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include "Player.h"
class Player;
class Account{
    private:
        Player *owner;
        double balance;
    public:
        Account();
        Account(const Account&);
        Account(Player*,double);
        double getBalance();
        Player* getOwner();
        void withdraw(double);
        void deposit(double);
        void changeOwner(Player*);
        std::string getOwnerName();
        friend std::ostream& operator<<(std::ostream&, const Account&);
};
#endif
