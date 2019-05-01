//
//  card.cpp
//  Program 1 War
//
//  Created by Nikki Nguyen on 2/7/17.
//  Copyright © 2017 Nikki Nguyen. All rights reserved.
//

#include "card.hpp"
#include <iostream>
#include <string>
using namespace std;
int suit;
int rank;
int value;
char letterRank;



Card::Card(){

    
}

void Card::setCard(int s, int r){
    suit = s;
    rank = r;
    
    
}

Card:: Card(int s, int r){
    suit = s;
    rank = r;
}
void Card:: displayCard(){
    char letterRank = rank;
    if (rank == 1) {
        letterRank = 'A';
       cout<<"ACE OF ";
    } else if (rank == 2) {
         letterRank = '2';
       cout<<"TWO OF ";
    } else if (rank == 3) {
         letterRank = '3';
        cout<<"THREE OF ";
    } else if (rank == 4) {
         letterRank = '4';
        cout<<"FOUR OF ";
    } else if (rank == 5) {
         letterRank = '5';
        cout<<"FIVE OF ";
    } else if (rank == 6) {
         letterRank = '6';
        cout<<"SIX OF ";
    } else if (rank == 7) {
         letterRank = '7';
        cout<<"SEVEN OF ";
    } else if (rank == 8) {
         letterRank = '8';
        cout<<"EIGHT 0F ";
    } else if (rank == 9) {
         letterRank = '9';
        cout<<"NINE OF ";
    } else if (rank == 10) {
         letterRank = 'T';
        cout<<"TEN OF ";
    } else if (rank == 11) {
        letterRank = 'J';
        cout<<"JACK OF ";
    } else if (rank == 12) {
        letterRank = 'Q';
        cout<<"QUEEN OF ";
    } else if (rank == 13) {
        letterRank = 'K';
        cout<<"KING OF ";
    }
    if (suit == 1) {
        cout<<"SPADES\n";
        cout<<" ------------- \n"
        "["<<letterRank<<"            ] \n"
        "[             ] \n"
        "[   (｡♠‿♠｡)   ] \n"
        "[   (｡♠‿♠｡)   ] \n"
        "[   (｡♠‿♠｡)   ] \n"
        "[             ] \n"
        "[            "<<letterRank<<"] \n"
        " ------------- \n";
    } else if (suit == 2) {
        cout<<"CLUBS\n";
        cout<<" ------------- \n"
        "["<<letterRank<<"            ] \n"
        "[             ] \n"
        "[   (｡♣‿♣｡)   ] \n"
        "[   (｡♣‿♣｡)   ] \n"
        "[   (｡♣‿♣｡)   ] \n"
        "[             ] \n"
        "[            "<<letterRank<<"] \n"
        " ------------- \n";
    } else if (suit == 3) {
        cout<<"DIAMONDS\n";
        cout<<" ------------- \n"
        "["<<letterRank<<"            ] \n"
        "[             ] \n"
        "[   (｡♦‿♦｡)   ] \n"
        "[   (｡♦‿♦｡)   ] \n"
        "[   (｡♦‿♦｡)   ] \n"
        "[             ] \n"
        "[            "<<letterRank<<"] \n"
        " ------------- \n";
    } else if (suit == 4) {
        cout<<"HEARTS\n";
        cout<<" ------------- \n"
        "["<<letterRank<<"            ] \n"
        "[             ] \n"
        "[   (｡♥‿♥｡)   ] \n"
        "[   (｡♥‿♥｡)   ] \n"
        "[   (｡♥‿♥｡)   ] \n"
        "[             ] \n"
        "[            "<<letterRank<<"] \n"
        " ------------- \n";
    }
    
}

int Card:: getValue(){
    return rank;
}


