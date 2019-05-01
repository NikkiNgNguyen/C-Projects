//
//  card.hpp
//  Program 1 War
//
//  Created by Nikki Nguyen on 2/7/17.
//  Copyright © 2017 Nikki Nguyen. All rights reserved.
//

#ifndef card_hpp
#define card_hpp

#include <stdio.h>


class Card{
private:
    int rank;
    int suit;
public:
    Card();
    void setCard(int s, int r);
    Card(int s, int r);
    int getValue();
    void displayCard();
};

#endif /* card_hpp */
