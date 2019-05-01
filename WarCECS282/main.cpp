//Nikki Nguyen
//CECS 282
//Program 1 - War
//February 14, 2017

#include "card.hpp"
#include "deck.hpp"
#include <iostream>
using namespace std;

int main() {
    //comp clock
    clock_t time;
    time = clock();
    
    int randTime = (time)/(double)(CLOCKS_PER_SEC/1000000);
    srand(randTime);
    
    Deck myDeck;
    int menuLoop = true;
    while (menuLoop){
        cout<<"\n\n";
        cout<<"War\n";
        cout<<"Please select an option from the menu: \n"
        "[1] New Deck\n"
        "[2] Display all Cards Remaining in Deck\n"
        "[3] Shuffle Cards in Deck\n"
        "[4] Play War\n"
        "[5] Quit\n";
    int menuChoice;
    cin>>menuChoice;
        switch(menuChoice){
            case 1:{
                cout<<"\n\n";
                cout<<"New Deck Done \n";
                cout<<"";
                myDeck.resetDeck();
                break;
            }
            case 2:{
                cout<<"\n\n";
                cout<<"Cards Left: "<<myDeck.cardsLeft()<<"\n";
                cout<<"";
                myDeck.displayDeck();
                break;
            }
            case 3:{
                cout<<"\n\n";
                cout<<"Shuffling...\n";
                cout<<"";
                myDeck.shuffle();
                break;
            }
            case 4:{
                    cout<<"Get ready to play WAR!!!\n";
                    cout<<"There are "<<myDeck.cardsLeft()<<" cards in the deck\n";
                    cout<<"\n\n";
                    int playable = true;
                    //while(playable){
                        int you = 0;
                        int me = 0;
                        cout<<"...dealing...\n";
                        cout<<"\n\n";
                        cout<<"One for you...\n";
                        you = myDeck.deal();
                        cout<<"One for me...\n";
                        me = myDeck.deal();
                        cout<<"\n\n";
                        
                        if(you == me){
                            cout<<"Tie Game! Play again?\n";
                            cout<<"\n\n";
                        }else if( you > me){
                            cout<<"You Win! Play again?\n";
                            cout<<"\n\n";
                        }else{
                            cout<<"I Win! Play again?\n";
                            cout<<"\n\n";
                        
                        }
                        cout<<"Cards Left: "<<myDeck.cardsLeft()<<"\n";
                        if(myDeck.cardsLeft() == 0){
                            playable = false;
                            cout<<"Not enough cards, remake the deck";
                        }else{
                            cout<<"Play again?";
                        }
                    }
                    break;
           //}
                
            case 5:{
                cout<<"";
                cout<<"Goodbye!\n";
                menuLoop = false;
                break;
            }
        }
    }

    return 0;



}
