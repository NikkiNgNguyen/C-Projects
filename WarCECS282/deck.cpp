//
//  deck.cpp
//  Program 1 War
//
//  Created by Nikki Nguyen on 2/7/17.
//  Copyright © 2017 Nikki Nguyen. All rights reserved.
//
#include "card.hpp"
#include "deck.hpp"
#include <iostream>
#include <ctime>
#include<cstdlib>//rand and srand
using namespace std;


Card storage[52];
int cardCount;

Deck::Deck(){
    int count = 0;
    for(int s = 1; s < 5; s++){
        for(int r = 1; r < 14; r++){
            storage[count] = Card(s,r);
            count++;
        }
    }
    cardCount = 52;
}

void Deck:: displayDeck(){
    for(int i = 0; i < cardCount; i++){
        storage[i].displayCard();
    }
    
}

int Deck:: deal(){
    //return storage[--cardCount];
    if(cardCount <=0){
        return 0;
        
    }else {
        cardCount--;
        storage[cardCount].displayCard();
        return storage[cardCount].getValue();
    }
}

int Deck::cardsLeft(){
    return cardCount;
}


void Deck:: shuffle(){
    for (int i = 0; i < 1000; i++) {
        int index1 = rand()%52;
        int newIndex = rand()%52;
        Card swap = storage[index1];
        storage[index1] = storage[newIndex];
        storage[newIndex] = swap;
        
    }
}

void Deck:: resetDeck(){
    int count = 0;
    for(int s = 1; s < 5; s++){
        for(int r = 1; r < 14; r++){
            storage[count] = Card(s,r);
            count++;
            
        }
        
    }
    cardCount = 52;
}
