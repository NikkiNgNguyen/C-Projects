//Nikki Nguyen
//Prog 4 - Overloading Operators
//CECS 282 Gold
//Due: 4/4/2017
#include <iostream>
#include "upDate.hpp"
#include <string>

using namespace std;

int day;
int month;
int year;
static int dCount;

upDate:: upDate(){
    //HAPPY BIRTHDAY!!!!
    month = 5;
    day = 11;
    year = 1959;
    //new
    date = new int[3];
    date[0] = month;
    date[1] = day;
    date[2] = year;
    dCount++;
    
    
}
upDate:: upDate(int M, int D, int Y){
    date = new int[3];
    date[0] = M;
    date[1] = D;
    date[2] = Y;
    dCount++;
}

void upDate::setDate(int M, int D, int Y){
    date = new int[3];
    date[0] = M;
    date[1] = D;
    date[2] = Y;
    dCount++;
}

upDate::upDate(const upDate &D) {
    date = new int[3];
    date[0] = D.date[0];
    date[1] = D.date[1];
    date[2] = D.date[2];
    dCount++;
}

upDate::~upDate(){
    delete[]date;
    dCount--;
}

int upDate:: getMonth(){
    return date[0];
}
int upDate:: getDay(){
    return date[1];
    
}
int upDate:: getYear(){
    return date[2];
    
}

int upDate:: daysBetween(upDate D){
    int first,last;
    first = julian();
    last = D.julian();
    return abs(last - first);
    
}



void upDate:: display(){
    string monthName;
    
    switch (date[0]) {
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
    monthName = to_string(date[0]) + "/" + to_string(date[1]) + "/" + to_string(date[2]);
    cout << monthName;
    
    
}


int upDate::GetDateCount(){
    return dCount;
}

int upDate::julian(){
    return gToJ(getMonth(), getDay(), getYear());
}



int upDate:: dayOfYear(){
    int dayOfYear = gToJ(date[0], date[1], date[2]);
    int last = gToJ(1, 1, date[2]);
    dayOfYear = dayOfYear - last + 1;
    
    return dayOfYear;
}

void upDate::jToG(int JD, int &M, int &D, int &Y) {
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
    
    Y = I;
    M = J;
    D = K;
    
    if (year != I | month != J | day != K) {
        I = 1959;
        J = 5;
        K = 11;
        
        year = I;
        month = J;
        day = K;
    }
}


int upDate::gToJ(int M, int D, int Y) {
    return D - 32075 + 1461 * (Y + 4800 + (M - 14) / 12) / 4 + 367 * (M - 2 - (M - 14) / 12 * 12) / 12 - 3 * ((Y + 4900 + (M - 14) / 12) / 100) / 4;
}

void upDate:: GDtoJD(int JD){
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

void upDate:: incrDate(int N){
    int jdCount = gToJ(date[0], date[1], date[2]) + N;
    jToG(jdCount, date[0], date[1], date[2]);
}

void upDate:: decrDate(int N){
    int jdCount = gToJ(date[0], date[1], date[2]) - N;
    jToG(jdCount, date[0], date[1], date[2]);
    
}

upDate upDate::operator=(upDate D) {
    date[0] = D.date[0];
    date[1] = D.date[1];
    date[2] = D.date[2];
    return (*this);
}

upDate upDate::operator++(int x) {
    upDate temp(*this);
    incrDate(1);
    return temp;
}

upDate upDate::operator++() {
    upDate temp(*this);
    temp.incrDate(1);
    return temp;
}

upDate upDate::operator+(int x) {
    upDate temp(*this);
    temp.incrDate(x);
    return temp;
}

upDate operator+(int x, upDate D) {
    return (D + x);
}

int operator-(upDate D, upDate D2) {
    return D.daysBetween(D2);
}

upDate upDate::operator--(int x) {
    upDate temp(*this);
    decrDate(1);
    return temp;
}

upDate upDate::operator--() {
    upDate temp(*this);
    temp.decrDate(1);
    return temp;
}

upDate upDate::operator-(int x) {
    upDate temp(*this);
    temp.decrDate(x);
    return temp;
}

upDate operator-(int x, upDate D) {
    return (D - x);
}

bool upDate::operator<(upDate D) {
    if (gToJ(getMonth(), getDay(), getYear()) < gToJ(D.getMonth(), D.getDay(), D.getYear())) {
        return true;
    }
    else
        return false;
}

bool upDate::operator>(upDate D) {
    if (gToJ(getMonth(), getDay(), getYear()) > gToJ(D.getMonth(), D.getDay(), D.getYear())) {
        return true;
    }
    else
        return false;
}

bool upDate::operator==(upDate D) {
    if (gToJ(getMonth(), getDay(), getYear()) == gToJ(D.getMonth(), D.getDay(), D.getYear())) {
        return true;
    }
    else
        return false;
}

ostream &operator<<(ostream &cout, upDate D) {
    D.display();
    return cout;
}

















