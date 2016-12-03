#include <iostream>
#include "Player.h"

Player::Player(){
    name = "John Doe";
}
Player::Player(const Player& pl){
    this->name = pl.name;
    this->hnd = pl.hnd;
    this->ac = pl.ac;
}
Player::Player(std::string name){
    this->name = name;
}
Player::Player(std::string name, Hand* hand, Account* acc){
    this->name = name;
    this->hnd = hand;
    this->ac = acc;
}
Player::~Player(){
}
std::string Player::getName(){
    return name;
}
Account* Player::getAccount(){
    return ac;
}
Hand* Player::getHand(){
    return hnd;
}
std::ostream& operator<<(std::ostream& out, const Player& pl){
    out << pl.name;
    return out;
}
void Player::setName(std::string nam){
    this->name = nam;
}
void Player::bet(double b){
    be = b;
    ac->withdraw(b);
}
void Player::doubleBet(){
    ac->withdraw(be);
    be=be*2;
}
void Player::win(){
    ac->deposit(be*2);
    be=0;
}
void Player::blackjack(){
    ac->deposit((be*2)+(be/2));
    be=0;
}
