#include <iostream>
#include "GameCarrier.h"

using namespace std;

GameCarrier::GameCarrier(){
    sizpl = 0;
    sizhnd = 0;
    sizacc = 0;
}
GameCarrier::GameCarrier(Player* pl, Hand* hnd, Account* acc, int siz){
    this->pl = new Player[siz];
    this->hnd = new Hand[siz];
    this->acc = new Account[siz];
    int i;
    for(i=0;i<siz;i++){
        this->pl[i]=pl[i];
        this->hnd[i]=hnd[i];
        this->acc[i]=acc[i];
    }
    this->siz = this->sizpl = this-> sizacc = this->sizhnd = siz;
}
GameCarrier::GameCarrier(int a){
    this->siz = this->sizpl = this-> sizacc = this->sizhnd = a;
    this->pl = new Player[a];
    this->hnd = new Hand[a];
    this->acc = new Account[a];
}
GameCarrier::~GameCarrier(){
    delete []pl;
    delete []hnd;
    delete []acc;
}
void GameCarrier::addHand(Hand* han){
    Hand arr[sizhnd+1];
    int i;
    for(i=0;i<sizhnd;i++){
        arr[i]=hnd[i];
    }
    arr[i]= *han;
    delete []hnd;
    sizhnd++;
    hnd = new Hand[sizhnd];
    for(i=0;i<sizhnd;i++){
        hnd[i]=arr[i];
    }
}
void GameCarrier::addAccount(Account* ac){
    Account arr[sizacc+1];
    int i;
    for(i=0;i<sizacc;i++){
        arr[i]=acc[i];
    }
    arr[i]= *ac;
    delete []acc;
    sizacc++;
    acc = new Account[sizacc];
    for(i=0;i<sizacc;i++){
        acc[i]=arr[i];
    }
}
void GameCarrier::addPlayer(Player* p){
    Player arr[sizpl+1];
    int i;
    for(i=0;i<sizpl;i++){
        arr[i]=pl[i];
    }
    arr[i] = *p;
    delete []pl;
    sizpl++;
    pl = new Player[sizpl];
    for(i=0;i<sizpl;i++){
        pl[i] = arr[i];
    }
}
void GameCarrier::addInstance(Player* p,Account* ac, Hand* hn){
    addPlayer(p);
    addAccount(ac);
    addHand(hn);
    siz++;
}
void GameCarrier::remAccount(int pos){
    Account arr[sizacc];
    int i,j;
    for(i=0,j=0;i<sizacc;i++){
        if(i!=pos){
            arr[j] = acc[i];
            j++;
        }
    }
    delete []acc;
    sizacc--;
    acc = new Account[sizacc];
    for(i=0;i<sizacc;i++){
        acc[i] = arr[i];
    }
}
void GameCarrier::remHand(int pos){
    Hand arr[sizhnd];
    int i, j;
    for(i=0,j=0;i<sizhnd;i++){
        if(i!=pos){
            arr[j] = hnd[i];
            j++;
        }
    }
    delete []hnd;
    sizhnd--;
    hnd = new Hand[sizhnd];
    for(i=0;i<sizhnd;i++){
        hnd[i] = arr[i];
    }
}
void GameCarrier::remPlayer(int pos){
    Player arr[sizpl - 1];
    int i, j;
    for(i=0,j=0;i<sizpl;i++){
        if(i!=pos){
            arr[j] = pl[i];
            j++;
        }
    }
    delete []pl;
    sizpl--;
    pl = new Player[sizpl];
    for(i=0; i<sizpl; i++){
        pl[i] = arr[i];
    }
}
void GameCarrier::remInstance(int pos){
    remPlayer(pos);
    remHand(pos);
    remAccount(pos);
    siz--;
}
void GameCarrier::printPlayers(){
    int i;
    for(i=0;i<sizpl;i++){
        cout << (i+1) << ". " << pl[i] << endl;
    }
}
void GameCarrier::printAccounts(){
    int i;
    for(i=0;i<sizacc;i++){
        cout << acc[i] << endl;
    }
}
void GameCarrier::printHands(){
    int i;
    for(i=0;i<sizhnd;i++){
        cout << "Hand " << (i+1) << ":" << endl;
        hnd[i].printDeck();
        cout << endl;
    }
}
Player* GameCarrier::getPlayer(int x){
    return &pl[x];
}
