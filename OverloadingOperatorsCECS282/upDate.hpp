//
//  upDate.hpp
//  Proj 4 Overloading Operators
//
//  Created by Nikki Nguyen on 3/14/17.
//  Copyright © 2017 Nikki Nguyen. All rights reserved.
//
#include<iostream>
#include <string>
#ifndef myDate_hpp
#define myDate_hpp
#include<iostream>
#include <stdio.h>

class upDate{
private:
    int month;
    int day;
    int year;
    int *date;
public:
    upDate();
    upDate(int M, int D, int Y);
    //new
    upDate(const upDate &D);
    //new
    ~upDate();
    void display();
    void incrDate(int N);
    void decrDate(int N);
    int daysBetween(upDate D);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    void jToG(int JD, int &M, int &D, int &Y);
    int gToJ(int M, int D, int Y);
    void GDtoJD(int JD);
    //new
    upDate operator=(upDate D);
    upDate operator+(int x);
    upDate operator-(int x);
    friend upDate operator+(int x, upDate D);
    friend int operator-(upDate D, upDate D2);
    friend upDate operator-(int x, upDate D);
    upDate operator++();
    upDate operator++(int x);
    upDate operator--();
    upDate operator--(int x);
    bool operator<(upDate D);
    bool operator>(upDate D);
    bool operator==(upDate D);
    void setDate(int M, int D, int Y);
    friend std::ostream &operator<<(std::ostream &cout, upDate D);
    static int GetDateCount();
    int julian();
    
};

#endif /* myDate_hpp */
