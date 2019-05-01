//
//  BigInt.hpp
//  PowerToolsProg5
//
//  Created by Nikki Nguyen on 4/4/17.
//  Copyright © 2017 Nikki Nguyen. All rights reserved.
//

#ifndef BigInt_hpp
#define BigInt_hpp
#include<vector>
#include<map>
#include<string>
#include <stdio.h>
using namespace std;
class BigInt{
private:
    vector<int> storage;
    vector<int>::iterator it;
    vector<int>::reverse_iterator rit;
    int next();
public:
    BigInt(int n);
    BigInt(const BigInt &n);
    ~BigInt();
    int size();
    BigInt operator++(int);
    BigInt operator + (BigInt n);
    BigInt operator + (int n);
    BigInt operator - (BigInt n);
    friend BigInt operator +(int n, BigInt N);
    //friend BigInt UniverseMiles();
    BigInt operator*(const BigInt &n);
    BigInt operator *= (const BigInt &n);
    bool operator == (BigInt n);
    bool operator > (BigInt n);
    bool operator < (BigInt n);
    //bool operator < (int n);
    friend ostream &operator <<(ostream &out, const BigInt &n);
    void print();
    //BigInt operator =(int n);
};
#endif /* BigInt_hpp */
