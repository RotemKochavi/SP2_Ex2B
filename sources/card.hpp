#pragma once
#include <iostream>
#include <string>
#include <vector>


enum Value {ACE = 1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING};
enum Suit {CLUBS,DIAMONDS,HEARTS,SPADES};

using namespace std;
namespace ariel
{
    class Card 
    {
        private:
            string suit;
            int value;
        
        public:
            Card(int value = 1, string suit = "CLUBS" );
            string getsuit();
            int getvalue();
            void print_Card();
            bool empty();
            
        
    };
};
