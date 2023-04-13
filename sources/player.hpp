#pragma once

#include <iostream>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Player
    {
        private:
            vector<Card> hand_card;
            string name;
            int cardstaken;
            bool inGame;

        public:
            Player(string name);

            string getName() const
            {
                return name;
            }

            int cardesTaken() const
            {
                return cardstaken;
            }

            int stacksize() const
            {
                return (int)hand_card.size();
            }

            bool getInGame() const
            {
                return inGame;
            }

            void setInGame(bool status)
            {
                this->inGame = status;
            }

            void addCardTaken() {
                this->cardstaken++;
            }

            Card &getCard()
            {
                Card &ret = hand_card.back();
                this->hand_card.pop_back();
                return ret;
            }

            void addCard(const Card &card)
            {
                this->hand_card.push_back(card);
            }

            string toString() const
            {
                return getName() + " has " + to_string(stacksize()) +
                    " cards in hand and " + to_string(cardesTaken()) +
                    " cards taken.";
            }
    };
}
