#pragma once

#include <iostream>
#include <vector>
#include "card.hpp"
#include "player.hpp"

namespace ariel
{
    class Game
    {
        private:
            Player &player1, &player2;
            string lastStats, log;
            unsigned int turn;
            unsigned int draws;
            unsigned int p1Wins;
            unsigned int p2Wins;

        public:
            Game(Player &plr1, Player &plr2);

            void playTurn();

            void playAll();

            void printLastTurn() const {
                cout << lastStats << endl;
            }

            void printLog() const {
                cout << log << endl;
            }

            void printWiner() const;

            void printStats() const;
    };
}