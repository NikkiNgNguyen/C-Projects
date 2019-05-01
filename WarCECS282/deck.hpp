//
//  deck.hpp
//  Program 1 War
//
//  Created by Nikki Nguyen on 2/7/17.
//  Copyright © 2017 Nikki Nguyen. All rights reserved.
//
#include "card.hpp"
#ifndef DECK_H
#define DECK_H

#include <stdio.h>
class Deck{
private:
    Card storage[52];
    int cardCount;
public:
    Deck();
    void resetDeck();
    int deal();
    void shuffle();
    int cardsLeft();
    void displayDeck();
    
    
};

#endif /* deck_hpp */
