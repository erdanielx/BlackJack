#include <iostream>
#include "card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Account.h"
#include "GameCarrier.h"
#include "OptionGenerator.h"

using namespace std;

GameCarrier gc;
OptionGenerator op;
void startGame(){
    op.go(0);
    int num;
    cin >> num;
    int i;
    cout << "Enter player names:" << endl;
    string p[num];
    for(i=0;i<num;i++){
        cin >> p[i];
    }
    Player *x = new Player[num];
    for(i=0;i<num;i++){
        x[i].setName(p[i]);
        gc.addPlayer(&x[i]);
    }
    int w=op.go(1);
    if(w==2){
        gc.printPlayers();
        w = op.go(2);
        while(w!=0){
            while(w==3){
                string nam;
                cout << "Player's name: ";
                cin >> nam;
                Player *pla = new Player(nam);
                gc.addPlayer(pla);
                cout << "Now we have:" << endl;
                gc.printPlayers();
                w = op.go(2);
                num++;
            }
            while(w==4){
                int n;
                cout << "Number of player to remove: ";
                cin >> n;
                gc.remPlayer(n-1);
                cout << "Now we have:" << endl;
                gc.printPlayers();
                w = op.go(2);
                num--;
            }
        }
    }
    int y = op.go(3);
    Account *ac = new Account[num];
    if(y==5){
        cout << endl;
        double mon;
        for(i=0;i<num;i++){
            cout << "How much money does " << (gc.getPlayer(i))->getName() << " get?\n";
            cin >> mon;
            ac[i].deposit(mon);
            ac[i].changeOwner(gc.getPlayer(i));
            gc.addAccount(&ac[i]);
        }
    }
    else if(y==6){
        double mon;
        cout << endl << "How much money does everyone get?\n";
        cin >> mon;
        for(i=0;i<num;i++){
            ac[i].deposit(mon);
            ac[i].changeOwner(gc.getPlayer(i));
            gc.addAccount(&ac[i]);
        }
    }
    cout << endl << "This is what we have: " << endl;
    gc.printAccounts();
}
int main(){
    int play=true;
    startGame();
    while(play){
    }
    return 0;
}
