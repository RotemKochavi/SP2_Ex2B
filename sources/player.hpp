#pragma once

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Player
    {
        private:
            string name;
            bool inGame;
            vector<Card> hand_card;
        //   int cardsTaken
        //   int stacksize;
        //   int stackCard;
        //   int countWins;
        //   vector<Card> myStack;


        public:

        int cardstaken;
        int stacksize;
        int stackCard;
        int countWins;

        Player(string name);

        string getName();
        bool empty();
        bool getInGame();
        void setInGame(bool status);
        int cardsTaken();
        int stackSize();
        int getCountWins(int size);
        int counterWins();
        bool hasCard(Card card) const;
        int getStackCard();
        void pushBackCard(Card card_back);
        Card backCardStack();
        void popCardStack();
        void pushCardTaken(Card cardstaken);
        Card backCardTaken();
        void popCardTaken();
        void addCardsTaken();
        Card getCard();
        void removeCard();
        string to_string();
    };
};

#endif