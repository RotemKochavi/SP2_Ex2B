#pragma once

#include <vector>
#include "card.hpp"
#include"player.hpp"
#include <iostream>


namespace ariel
{
    class Game
    {
        private:
        int value;
        string suit;
        Player &p1, &p2;
        vector<Card> hand_card, p1Cards, p2Cards;
        string lastStats, log;
        int cardsTaken;
        unsigned int turn;
         int p1Wins;
         int p2Wins;
        unsigned int winner;

        unsigned int draws;

        public:
            Game(Player& player1, Player& player2);
            void playTurn();
            void printLastTurn();
            void playAll();
            void printLog() const;
            bool getIsTurn();
            void printWiner();
            void creatCard();
            void shuffle();
            void ret_card();
            void printStats();
            string getName();
        //    void pushBackCard(Card card_back);
            Card getCard();
            bool getIsTurn();
            string getName();

    };
}