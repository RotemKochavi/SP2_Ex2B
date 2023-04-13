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
    Game::Game(Player& player1, Player &player2) : p1(player1), p2(player2), turn(0)
    {
    
       if (p1.getInGame() || p2.getInGame())
        throw logic_error("One of the players is already in game.");

        this->p1.setInGame(true);
        this->p2.setInGame(true);
        bool isTurn;
        creatCard();
        shuffle();
        ret_card();

    }
    
    string s_suit, s_value;

void Game::creatCard()
    {
          switch (Suit)
        {
            case CLUBS:
                s_suit = "CLUBS";
                break;
            case DIAMONDS:
                s_suit = "DIAMONDS";
                break;
            case HEARTS:
                s_suit = "HEARTS";
                break;
            case SPADES:
                s_suit = "SPADES";
                break;
        }

            switch (value)
            {
            case ACE:
                s_value = "ACE";
                break;
            case JACK:
                s_value = "JACK";
                break;
            case QUEEN:
                s_value = "QUEEN";
                break;
            case KING:
                s_value = "KING";
                break;
            default:
                s_value = to_string((int)value);
                break;
            }   
    }

void Game:: shuffle() //https://www.javatpoint.com/cpp-algorithm-shuffle-function
{
    random_device r_d;
    mt19937 gen(r_d());
    shuffle(this->hand_card.begin(), this->hand_card.end(), gen);
}

void Game:: ret_card() //##################################
{
    for(int i=0; i<=52; i++)
    {
        if( i<=25)
            p1->pushBackCard(this->hand_card[i]);
        else{
            p2->pushBackCard(this->hand_card[i]);
        }
    }
}

void Game::playTurn()
    {
        

        if (&p1 == &p2)
            throw logic_error("Player can't play with himself.");
        
        string log = "";
        bool flag = turn;
        vector<Card> deck;
        unsigned int turn_number = 0;
        unsigned int p1Wins =0 , p2Wins = 0, winner=0;
        this->lastStats = "";
        
        if (p1.getInGame() && p2.getInGame())
        {
           this->turn++;
            if ( 26 < this->turn )
                throw logic_error("The game can't continue with more than 26 turns.");
   
            Card p1Card = p1.getCard();
            Card p2Card = p2.getCard();
            p1.removeCard();
            p2.removeCard();
        
            cout << p1.getName() << "played" << p1Card.print_Card << " " ;
            cout << p2.getName() << "played" << p2Card.print_Card << " " ;
            this->lastStats = "Round " + to_string(this->turn) + ":  " + p1.getName() + " played " + p1Card.toString() + " " + p2.getName() + " played " + p2Card.to + ". ";
        
        
            if (p1Card > p2Card) 
            {
                cout << p1.getName << "wins in this round!\n";
                this-> p1Wins++;
                p2.addCardsTaken();

                while(!p2Card.empty())
                {
                    p1.cardsTaken();
                    p2Cards.back();
                }

                while(!p1Cards.empty())
                {
                    p2.addCardsTaken();
                    p1Cards.back();
                }
            }
                
            if (p1Card < p2Card) 
            {
                cout << p2.getName << "wins in this round!\n";
                this-> p2Wins++;
                p1.addCardsTaken();

                while(!p2Card.empty())
                {
                    p1.addCardsTaken();
                    p1Cards.back();
                }

                while(!p1Cards.empty())
                {
                    p2.addCardTaken();
                    p1Cards.back();
                }
            }
        
            if (!p1.stackSize() || !p2.stackSize())
            {
                    p1.setInGame(false);
                    p2.setInGame(false);

                    if ((p1.cardsTaken() < p2.cardsTaken()))
                        this->winner = &p2;
                    else 
                        this->winner = &p1;
            }

                this->log += this->lastStats;

        }
      
        else
            throw logic_error ("The game is over!");
    }

   
    
    void Game::playAll()
    {
         if(p1.stackSize() == 0)
            throw logic_error("The game is over!");
        
        while(p1.stackSize() > 0)
            playTurn();
    }

    void Game::printWiner() //error
    {
        if (p1.getInGame() || p2.getInGame())
            return;
        
        else if (p1.cardsTaken() > p2.cardsTaken())
            cout << p1.getName() + " is the winner!!" << endl;
    
        else if (p1.cardsTaken() < p2.cardsTaken())
            cout << p2.getName() + " is the winner!" << endl;
        
        else
            cout << "Draw!" << endl;
    }

     void Game::printStats() //error p1,p2
    {
        cout << "Player " << p1.getName() << "status: " << endl;
        cout << "Won " << to_string(p1Wins) << "times" << endl;
        cout << "Cards won: " << p1.cardsTaken() << endl;
        cout << "Player " << p2.getName() << " status:" << endl;
        cout << "Won " << to_string(p2Wins) << "times" << endl;
        cout << "Cards won: " << p2.cardsTaken() << endl;
        cout << "Number of turns: " << this->turn << endl;
    }


    void Game::printLastTurn(){ cout << lastStats << endl;}
   
    void Game::printLog() const {cout << log << endl;}
   
    bool Game::getIsTurn(){ return this-> turn;}
} 