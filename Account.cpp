#include <iostream>
#include "Account.h"

Account::Account(){
    balance = 0;
}
Account::Account(const Account& ac){
    owner = ac.owner;
    balance = ac.balance;
}
Account::Account(Player* p, double bal){
    balance = bal;
    owner = p;
}
double Account::getBalance(){
    return balance;
}
Player* Account::getOwner(){
    return owner;
}
void Account::withdraw(double x){
    balance-=x;
}
void Account::deposit(double x){
    balance+=x;
}
void Account::changeOwner(Player* ow){
    owner = ow;
}
std::string Account::getOwnerName(){
    return owner->getName();
}
std::ostream& operator<<(std::ostream& out, const Account& ac){
    out << ac.owner->getName() << ": " << ac.balance;
    return out;
}
