#include "card.hpp"

using namespace ariel;

bool Card::operator<(Card &other) const
{
    if (this->value == ACE && other.value == TWO)
        return true;

    if (this->value > TWO && other.value == ACE)
        return true;

    return this->value < other.value;
}

string Card::getCardString()
{
    string ret;

    if (this->value == ACE)
        ret = "Ace of ";

    else if (this->value == JACK)
        ret = "Jack of ";

    else if (this->value == QUEEN)
        ret = "Queen of ";

    else if (this->value == KING)
        ret = "King of ";

    else
        ret = to_string((int)this->value) + "of ";

    if (this->suit == CLUBS)
        ret += "Clubs";

    else if (this->suit == DIAMONDS)
        ret += "Diamonds";

    else if (this->suit == HEARTS)
        ret += "Hearts";

    else
        ret += "Spades";

    return ret;
}
