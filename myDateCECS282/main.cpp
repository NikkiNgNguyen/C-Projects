
//
//Nikki Nguyen
//CECS 282
//Prog 2 - myDate
//Feb 28, 2017
//  main.cpp
//  myDate
//
//  Created by Nikki Nguyen on 2/27/17.
//  Copyright © 2017 Nikki Nguyen. All rights reserved.
//

#include <iostream>
#include "myDate.hpp"
#include <stdlib.h>
#include<string>

using namespace std;
int main()
{
    myDate Bday;
    myDate duedate(2,28,2017);
    
    int x;
    int month, day, year;
    
    Bday.display();
    cout << endl;
    duedate.display();
    cout << endl;
    x = Bday.daysBetween(duedate);
    cout << "Master Gold is "<< x << " days old today";
    cout << endl;
    
    Bday.incrDate(x);
    
    cout << "Now these 2 dates should be the same:";
    Bday.display();
    cout << '\t';
    duedate.display();
    cout << "\n\n";
    
    
    month = duedate.getMonth();
    day = duedate.getDay();
    year = duedate.getYear();
    
    duedate.display();
    cout << " is also equal to "<<month<<"/"<<day<<"/"<<year<<endl;
    
    myDate July4(7,4,2016);
    cout << "This year the 4th of July will happen "<< (July4.dayOfYear()-1) << "days after New Years\n\n";
    
    myDate bogus(23,12,2007);
    cout << "The value of the bogus date is:";
    bogus.display();
    cout << endl;
    
    myDate D5(8,21,2007);
    x = D5.dayOfYear();
    D5.decrDate(x-1);
    cout << "Happy Newyear 2007 happened on:";
    D5.display();
    cout << endl;
    
    cout << "Today is "<< duedate.dayOfWeek()<<endl;
    cout << "Master Gold was born on "<< Bday.dayOfWeek()<<endl;
    
    myDate today = duedate;
    cout << "\nHere are the dates for the next 2  weeks:\n";
    for (int i=0; i<14; i++)
    {
        today.display();
        cout << ":"<<today.dayOfWeek() << endl;
        today.incrDate(1);
    }
    
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    cout<<"";
    //system("pause");
    return 0;
}
