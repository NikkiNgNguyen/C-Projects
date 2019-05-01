#include "BigInt.hpp"
#include "PowerTools.hpp"
#include <iostream>
#include <map>
#include <iomanip>
#include <cstdlib>
using namespace std;

// this version is too slow. use a <map> to make it faster
int fibo(int n)
{
    static map<int,int> fiboMap;
    if(fiboMap.find(n)!=fiboMap.end()){
        //cout<<"found in cache: " << n << " -> " <<fiboMap[n]<< endl;
        return fiboMap[n];
    }
    if(n == 0 || n == 1)
        return 1;
    else
        return fiboMap[n] = fibo(n-1)+fibo(n-2);
        //else
        //m[id] += g
}

// this version of fact does not catch overflow - needs to identify overflow and throw exception
int fact(int n)
{
    if (n > 16)
        throw n;
    if (n == 0)
        return 1;
    else return n * fact(n-1);
}

int exp(int x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return y;
    else
        return x * exp(x, y-1);
}

//BigInt fibo(BigInt Bx){
//    static map<BigInt,BigInt> fiboMap;
//    if(fiboMap.find(Bx)!=fiboMap.end()){
//        cout<<"found in cache: " << Bx << " -> " <<fiboMap[Bx]<< endl;
//        return fiboMap[Bx];
//    }
//    if(Bx == 0 || Bx == 1)
//        return 1;
//    else
//        return fiboMap[Bx] = fibo(Bx-1)+fibo(Bx-2);
//
//    
//}
BigInt fact(BigInt Bx){
    if (Bx > 16)
        throw Bx;
    if (Bx == 0)
        return 1;
    else return Bx * fact(Bx-1);
}

BigInt exp(BigInt Bx , BigInt By){
    if (By == 0)
        return 1;
    if (By == 1)
        return By;
    else
        return Bx * exp(Bx, By-1);
}
BigInt exp(BigInt Bx, int y){
    if (y == 0)
        return 1;
    if (y == 1)
        return y;
    else
        return Bx * exp(Bx, y-1);
}



/*
 Universe is 93 Billion light years across https://www.universetoday.com/36302/atoms-in-the-universe/
 
 Light travels at 186,282 miles/second
 There are 365.2425 days in a year.
 How far is the universe from end to end in miles?
 Write this function: BigInt UniverseMiles( );
 Answer: 54669978319152000000000
 */


BigInt UniverseMiles(){
    BigInt lightYearPerMile(9300000);
    BigInt dayPerYear(3652425);
    BigInt hrPerDay(24);
    BigInt minPerHr(60);
    BigInt secPerMin(60);
    BigInt milePerSec(186282);
    return lightYearPerMile * dayPerYear * hrPerDay * minPerHr * secPerMin * milePerSec;
    
    
}
