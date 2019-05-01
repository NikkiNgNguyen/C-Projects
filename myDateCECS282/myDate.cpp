//
//Nikki Nguyen
//CECS 282
//Prog 2 - myDate
//Feb 28, 2017
//
//  myDate.cpp
//  myDate
//
//  Created by Nikki Nguyen on 2/27/17.
//  Copyright © 2017 Nikki Nguyen. All rights reserved.
//
#include <cmath>
#include <iostream>
#include "myDate.hpp"
#include <string>
using namespace std;

int day;
int month;
int year;


//int greg2Julian(int month, int day, int year){}

//void julian2Greg(int JD, int & month, int & day, int & year){}

myDate:: myDate(){
    //HAPPY BIRTHDAY!!!!
    day = 11;
    month = 5;
    year = 1959;
   
    
}
myDate:: myDate(int M, int D, int Y){
    if (M > 0 && M < 13) {
        month = M;
        if (D > 0 && D < 32) {
            day = D;
            year = Y;
        }
    }
    else {
        month = 5;
        day = 11;
        year = 1959;
    }

    
}

void myDate:: display(){
    string monthName;
    
    switch (month) {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
    }
    monthName = monthName + " " + to_string(day) + ", " + to_string(year);
    cout << monthName;
    
    
}

void myDate:: incrDate(int N){
    int j = JD(year, month, day);
    if (N < 0) {
        N = -N;
    }
    j += N;
    int x, y, z;
    GDate(j, x, y, z);
    year = x;
    month = y;
    day = z;
}

void myDate:: decrDate(int N){
    int j = JD(year, month, day);
    
    if (N < 0) {
        N = -N;
    }
    
    j -= N;
    int x, y, z;
    GDate(j, x, y, z);
    year = x;
    month = y;
    day = z;
    
}

int myDate:: daysBetween(myDate D){
    int a, b;
    a = JD(D.getYear(), D.getMonth(), D.getDay());
    b = JD(year, month, day);
    
    return abs(b - a) ;
    
}

int myDate:: getMonth(){
    return month;
}
int myDate:: getDay(){
    return day;
    
}
int myDate:: getYear(){
    return year;
    
}
int myDate:: dayOfYear(){
    int dOfY = 0;
    if (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0))) {
        switch(month) {
            case 2:
                dOfY = 31;
                break;
            case 3:
                dOfY = 60;
                break;
            case 4:
                dOfY = 91;
                break;
            case 5:
                dOfY = 121;
                break;
            case 6:
                dOfY = 152;
                break;
            case 7:
                dOfY = 182;
                break;
            case 8:
                dOfY = 213;
                break;
            case 9:
                dOfY = 244;
                break;
            case 10:
                dOfY = 274;
                break;
            case 11:
                dOfY = 305;
                break;
            case 12:
                dOfY = 335;
                break;
            default:
                dOfY = 0;
                break;
        }
        
        dOfY = dOfY + day;
    }

    else {
        switch (month) {
            case 2:
                dOfY = 31;
                break;
            case 3:
                dOfY = 59;
                break;
            case 4:
                dOfY = 90;
                break;
            case 5:
                dOfY = 120;
                break;
            case 6:
                dOfY = 151;
                break;
            case 7:
                dOfY = 181;
                break;
            case 8:
                dOfY = 212;
                break;
            case 9:
                dOfY = 243;
                break;
            case 10:
                dOfY = 273;
                break;
            case 11:
                dOfY = 304;
                break;
            case 12:
                dOfY = 334;
                break;
            default:
                dOfY = 0;
                break;
        }
        
        dOfY = dOfY + day;
    }
    
    return dOfY;
    
}

std:: string myDate:: dayOfWeek(){
    int m, d, y;
    m = month;
    d = day;
    y = year;
    
    if (m == 1 || m == 2) {
        m = m + 12;
        y = y - 1;
    }
    //floor rounds down
    int zellerAlg = (d + (int)floor((13 * (m + 1)) / 5) + y % 100 + (int)floor((y % 100) / 4) + (int)floor(((int)floor(y / 100)) / 4) + 5 * (int)floor(y / 100)) % 7;
    
    string dayName;
    switch (zellerAlg) {
        case 0:
            dayName = "Saturday";
            break;
        case 1:
            dayName = "Sunday";
            break;
        case 2:
            dayName = "Monday";
            break;
        case 3:
            dayName = "Tuesday";
            break;
        case 4:
            dayName = "Wednesday";
            break;
        case 5:
            dayName = "Thursday";
            break;
        case 6:
            dayName = "Friday";
            break;
    }
    
    return dayName;
}
    
void myDate::GDate(int JD, int &year, int &month, int &day) {
    int I, J, K;
    int L, N;
    
    L = JD + 68569;
    N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    I = 4000 * (L + 1) / 1461001;
    L = L - 1461 * I / 4 + 31;
    J = 80 * L / 2447;
    K = L - 2447 * J / 80;
    L = J / 11;
    J = J + 2 - 12 * L;
    I = 100 * (N - 49) + I + L;
    
    year = I;
    month = J;
    day = K;
    
}

int myDate::JD(int y, int m, int d) {
    int jul = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
    return jul;
}
