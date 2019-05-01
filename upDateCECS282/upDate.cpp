
#include "upDate.hpp"
static int dateCounter;
#include <string>
#include<iostream>
using namespace std;
upDate::upDate() {
    month = 5;
    day = 11;
    year = 1959;
    date = new int[3];
    date[0] = month;
    date[1] = day;
    date[2] = year;
    dateCounter++;
}

upDate::upDate(int m, int d, int y) {
    date = new int[3];
    date[0] = m;
    date[1] = d;
    date[2] = y;
    dateCounter++;
}

upDate::upDate(const upDate &d) {
    date = new int[3];
    date[0] = d.date[0];
    date[1] = d.date[1];
    date[2] = d.date[2];
    dateCounter++;
}

upDate::~upDate() {
    delete[]date;
    dateCounter--;
}

int upDate::getMonth() {
    return date[0];
}

int upDate::getDay() {
    return date[1];
}

int upDate::getYear() {
    return date[2];
}

int upDate::daysBetween(upDate d) {
    int firstDay = gToJ(month, day, year);
    int finalDay = gToJ(d.getMonth(), d.getDay(), d.getYear());
    return finalDay - firstDay;
}

int upDate::gToJ(int m, int d, int y) {
    int i, j, k;
    i = y;
    j = m;
    k = d;
    
    return k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;
}

int upDate::dayOfYear() {
    int dayOfYear = gToJ(date[0], date[1], date[2]);
    int finalDay = gToJ(1, 1, date[2]);
    dayOfYear = dayOfYear - finalDay + 1;
    
    return dayOfYear;
}

int upDate::julian() {
    return gToJ(getMonth(), getDay(), getYear());
}

bool upDate::operator<(upDate d) {
    if (gToJ(getMonth(), getDay(), getYear()) < gToJ(d.getMonth(), d.getDay(), d.getYear())) {
        return true;
    }
    else
        return false;
}

bool upDate::operator>(upDate d) {
    if (gToJ(getMonth(), getDay(), getYear()) > gToJ(d.getMonth(), d.getDay(), d.getYear())) {
        return true;
    }
    else
        return false;
}

bool upDate::operator==(upDate d) {
    if (gToJ(getMonth(), getDay(), getYear()) == gToJ(d.getMonth(), d.getDay(), d.getYear())) {
        return true;
    }
    else
        return false;
}

upDate upDate::operator=(upDate d) {
    date[0] = d.date[0];
    date[1] = d.date[1];
    date[2] = d.date[2];
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

upDate operator+(int x, upDate d) {
    return (d + x);
}

int operator-(upDate d, upDate d2) {
    return d.daysBetween(d2);
}

upDate upDate::operator--(int x) {
    upDate temp(*this);
    decrDate(1);
    return temp;
}

upDate upDate::operator--() {
    upDate temp(*this);
    decrDate(1);
    return temp;
}

upDate upDate::operator-(int x) {
    upDate temp(*this);
    temp.decrDate(x);
    return temp;
}

upDate operator-(int x, upDate d) {
    return (d - x);
}

ostream &operator<<(ostream &out, upDate D) {
    D.display();
    return out;
}

void upDate::jToG(int jd, int &m, int &d, int &y) {
    int l, n, i, j, k;
    
    l = jd + 68569;
    n = 4 * l / 146097;
    l = l - (146097 * n + 3) / 4;
    i = 4000 * (l + 1) / 1461001;
    l = l - 1461 * i / 4 + 31;
    j = 80 * l / 2447;
    k = l - 2447 * j / 80;
    l = j / 11;
    j = j + 2 - 12 * l;
    i = 100 * (n - 49) + i + l;
    
    y = i;
    m = j;
    d = k;
    
    if (year != i | month != j | day != k) {
        i = 1959;
        j = 5;
        k = 11;
        
        year = i;
        month = j;
        day = k;
    }
}

void upDate::changeGDtoJD(int jd) {
    int l, n, i, j, k;
    
    l = jd + 68569;
    n = 4 * l / 146097;
    l = l - (146097 * n + 3) / 4;
    i = 4000 * (l + 1) / 1461001;
    l = l - 1461 * i / 4 + 31;
    j = 80 * l / 2447;
    k = l - 2447 * j / 80;
    l = j / 11;
    j = j + 2 - 12 * l;
    i = 100 * (n - 49) + i + l;
    
    year = i;
    month = j;
    day = k;
}

void upDate::incrDate(int d) {
    int incrJD = gToJ(date[0], date[1], date[2]) + d;
    jToG(incrJD, date[0], date[1], date[2]);
}

void upDate::decrDate(int d) {
    int incrJD = gToJ(date[0], date[1], date[2]) - d;
    jToG(incrJD, date[0], date[1], date[2]);
}

int upDate::GetDateCount() {
    return dateCounter;
}

void upDate::display() {
    string output;
    switch (date[0]) {
        case 1:
            output = "January";
            break;
        case 2:
            output = "February";
            break;
        case 3:
            output = "March";
            break;
        case 4:
            output = "April";
            break;
        case 5:
            output = "May";
            break;
        case 6:
            output = "June";
            break;
        case 7:
            output = "July";
            break;
        case 8:
            output = "August";
            break;
        case 9:
            output = "September";
            break;
        case 10:
            output = "October";
            break;
        case 11:
            output = "November";
            break;
        case 12:
            output = "December";
            break;
    }
    output = output + " " + to_string(date[1]) + ", " + to_string(date[2]);
    cout << output;
}
