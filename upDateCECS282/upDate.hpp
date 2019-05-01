#pragma once
#ifndef upDate_h
#define upDate_h

#include <stdio.h>
#include <iostream>
using namespace std;

class upDate {
private:
    int month;
    int day;
    int year;
    int *date;
public:
    upDate();
    upDate(int m, int d, int y);
    upDate(const upDate &date);
    ~upDate();
    int getMonth();
    int getDay();
    int getYear();
    int daysBetween(upDate d);
    int gToJ(int m, int d, int y);
    int dayOfYear();
    int julian();
    bool operator<(upDate d);
    bool operator>(upDate d);
    bool operator==(upDate d);
    upDate operator=(upDate d);
    upDate operator++(int x);
    upDate operator++();
    upDate operator+(int x);
    friend upDate operator+(int x, upDate d);
    friend int operator-(upDate d, upDate d2);
    upDate operator--(int x);
    upDate operator--();
    upDate operator-(int x);
    friend upDate operator-(int x, upDate d);
    friend ostream &operator<<(ostream &out, upDate d);
    void jToG(int jd, int &m, int &d, int &y);
    void changeGDtoJD(int jd);
    void incrDate(int d);
    void decrDate(int d);
    void display();
    static int GetDateCount();
    
    
};

#endif /* upDate_hpp */
