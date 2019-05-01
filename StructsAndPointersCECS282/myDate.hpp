//
//  myDate.hpp
//  myDate
//
//  Created by Nikki Nguyen on 2/27/17.
//  Copyright © 2017 Nikki Nguyen. All rights reserved.
//
#include <string>
#ifndef myDate_hpp
#define myDate_hpp

#include <stdio.h>

//int greg2Julian(int month, int day, int year);
//void julian2Greg(int JD, int & month, int & day, int & year);
class myDate{
private:
    int month;
    int day;
    int year;
public:
    myDate();
    myDate(int M, int D, int Y);
    void display();
    void incrDate(int N);
    void decrDate(int N);
    int daysBetween(myDate D);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    std:: string dayOfWeek();
    void GDate(int JD, int &y, int &m, int &d);
    int JD(int y, int m, int d);
    //new function
    int compareTo(myDate D);
};

#endif /* myDate_hpp */
