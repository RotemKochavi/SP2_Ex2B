#pragma once

#include <iostream>
#include <string>

enum Value
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

enum Suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

using namespace std;
namespace ariel
{
    class Card
    {
        private:
            Suit suit;
            Value value;

        public:
            Card(Value value = ACE, Suit suit = CLUBS) : value(value), suit(suit){};

            Suit getSuit() const
            {
                return suit;
            }

            Value getValue() const
            {
                return value;
            }

            string getCardString();

            bool operator<(Card &other) const;
    };
};
