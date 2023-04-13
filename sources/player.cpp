#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "player.hpp"
#include "card.hpp"

namespace ariel
{
    Player::Player(string Name) 
    {
        name = Name;
        inGame = false;
        countWins = 0;
        vactor<Card> hand_card;
        
        this->cardstaken = {};
        this->stacksize = {};
        this->stackCard = {};
       
    
    
    string Player:: getName() {return this->name;}
    bool Player:: empty(){return this->hand_card.empty();}
    bool Player:: getInGame(){return this-> inGame;}
    void Player:: setInGame(bool status){ this-> inGame = status;}
    int Player:: cardsTaken() {return this-> cardstaken;}
    int Player:: stackSize(){return this-> hand_card.size();}
    int Player:: getCountWins(int size){return this-> countWins;}
    int Player:: counterWins(){ return this-> countWins++;}
    
    int Player:: getStackCard(){return this->stackCard.size;}
    void Player:: pushBackCard(Card card_back){ this->stackCard.push_back(card_back);}
    Card Player:: backCardStack(){return this->stackCard.back();}
    void Player:: popCardStack(){this->stackCard.pop_back();}
    void Player:: pushCardTaken(Card card_taken) {this->cardstaken.push_back(card_taken);}
    Card Player:: backCardTaken(){return this->cardstaken.back();}
    void Player:: popCardTaken(){this->card_taken.pop_back();}
    void Player:: addCardsTaken(){this->cardstaken++;} 
    Card Player:: getCard() {return this->hand_card.back();}
    void Player:: removeCard(){this-> hand_card.pop_back();}
    string Player:: to_string(){return this->name + "hold +" + to_string(this-> stacksize()) + "card in this moment." ; }
    bool Player:: hasCard(Card card) const
    {
        for(int i=0; i< (this->stacksize()); i++)
        {
            Card c = this->hand_card.at(i);
            if(c.getsuit() == card.getsuit() && c.getvalue() == card.getvalue())
                return true;
        }
        return false;
    }
}
};