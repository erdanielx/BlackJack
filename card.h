#ifndef _CARD_H_
#define _CARD_H_
#include <iostream>

class Card{
    public:
        Card();
        Card(const Card&);
        ~Card();
        Card(std::string,std::string);
        void calculateValues();
        int getA();
        int getB();
        std::string getSuit();
        std::string getShow();
        friend std::ostream& operator<<(std::ostream&,const Card&);
    private:
        int valA;
        int valB;
        std::string suit;
        std::string show;
};
#endif
