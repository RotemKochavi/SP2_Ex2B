#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

using namespace ariel;
using namespace std;

namespace ariel
{
    Game::Game(Player &plr1, Player &plr2) : player1(plr1),
                                             player2(plr2),
                                             turn(0),
                                             draws(0),
                                             p1Wins(0),
                                             p2Wins(0)
    {

        if (player1.getInGame() || player2.getInGame())
            throw logic_error("One of the players is already in game.");

        this->player1.setInGame(true);
        this->player2.setInGame(true);

        vector<Card> cardsOnTable;

        for (int i = 1; i <= 13; i++)
        {
            cardsOnTable.push_back(Card((Value)i, CLUBS));
            cardsOnTable.push_back(Card((Value)i, SPADES));
            cardsOnTable.push_back(Card((Value)i, DIAMONDS));
            cardsOnTable.push_back(Card((Value)i, HEARTS));
        }

        unsigned seed = (unsigned)time(NULL);
        auto rng = default_random_engine(seed);
        shuffle(cardsOnTable.begin(), cardsOnTable.end(), rng);

        for (int i = 1; i <= 52; i++)
        {
            if (i % 2 == 0)
                player1.addCard(cardsOnTable.back());

            else
                player2.addCard(cardsOnTable.back());

            cardsOnTable.pop_back();
        }
    }

    void Game::playTurn()
    {
        if (&player1 == &player2)
            throw logic_error("Player can't play with himself.");

        if (!player1.getInGame() || !player2.getInGame())
            throw logic_error("Game ended!");

        this->turn++;

        if (26 < this->turn)
            throw logic_error("The game can't continue with more than 26 turns.");

        Card& p1Card = player1.getCard();
        Card& p2Card = player2.getCard();

        int cardsOnTable = 2;

        cout << player1.getName() << " played " << p1Card.getCardString() << " ";
        cout << player2.getName() << " played " << p2Card.getCardString() << " ";
        this->lastStats = "Round " + to_string(this->turn) + ":  " +
                          player1.getName() + " played " + p1Card.getCardString() + " " +
                          player2.getName() + " played " + p2Card.getCardString() + ". ";

        while (p1Card.getValue() == p2Card.getValue())
        {
            if (player1.stacksize() <= 1 || player2.stacksize() <= 1)
            {
                while (cardsOnTable > 0)
                {
                    player1.addCardTaken();
                    player2.addCardTaken();
                    cardsOnTable -= 2;
                }

                break;
            }

            this->lastStats += "Draw. ";

            player1.getCard();
            player2.getCard();

            p1Card = player1.getCard();
            p2Card = player2.getCard();

            cardsOnTable += 4;
        }

        if (p2Card < p1Card)
        {
            cout << player1.getName() << " wins in this round!\n";
            this->lastStats += player1.getName() + " wins in this round!\n";
            this->p1Wins++;

            while (cardsOnTable > 0 )
            {
                player1.addCardTaken();
                cardsOnTable--;
            } 
        }

        else if (p1Card < p2Card)
        {
            cout << player2.getName() << " wins in this round!\n";
            this->lastStats += player2.getName() + " wins in this round!\n";
            this->p2Wins++;
            
            while (cardsOnTable > 0 )
            {
                player2.addCardTaken();
                cardsOnTable--;
            } 
        }

        if (!player1.stacksize() || !player2.stacksize())
        {
            player1.setInGame(false);
            player2.setInGame(false);
        }

        this->log += this->lastStats;
    }

    void Game::playAll()
    {
        while (player1.stacksize() > 0 && player2.stacksize() > 0)
            playTurn();
    }

    void Game::printWiner() const
    {
        if (player1.getInGame() || player2.getInGame())
            return;

        else if (player1.cardesTaken() > player2.cardesTaken())
            cout << player1.getName() + " is the winner!!" << endl;

        else if (player1.cardesTaken() < player2.cardesTaken())
            cout << player2.getName() + " is the winner!" << endl;

        else
            cout << "Draw!" << endl;
    }

    void Game::printStats() const
    {
        cout << "Player " << player1.getName() << "status: " << endl;
        cout << "Won " << to_string(p1Wins) << "times" << endl;
        cout << "Cards won: " << player1.cardesTaken() << endl;
        cout << "Player " << player2.getName() << " status:" << endl;
        cout << "Won " << to_string(p2Wins) << "times" << endl;
        cout << "Cards won: " << player2.cardesTaken() << endl;
        cout << "Number of turns: " << this->turn << endl;
    }
}