#include <iostream>
#include <string>
#include <vector>

#include "card.hpp"

using namespace std;
using namespace ariel;


    Card::Card(int Value, string Suit) 
    {
        value = Value;
        suit = Suit;
    }

    int Card::getvalue() {return this-> value;}
    string Card:: getsuit() {return this->suit; }
    
    void Card:: print_Card() 
    {
        cout << value << " + " << suit <<" " << endl;
    }
