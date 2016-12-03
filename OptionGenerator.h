#include <iostream>
#include "card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Account.h"
#include "GameCarrier.h"

using namespace std;

class OptionGenerator{
    public:
        OptionGenerator();
        ~OptionGenerator();
        int go(int);
};
