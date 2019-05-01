//
//  BigInt.cpp
//  PowerToolsProg5
//
//  Created by Nikki Nguyen on 4/4/17.
//  Copyright © 2017 Nikki Nguyen. All rights reserved.
//
#include "PowerTools.hpp"
#include "BigInt.hpp"
#include <iostream>
#include <string>

//BigInt::BigInt(){
//    
//}

BigInt::BigInt(int n){
    //for (int i = 0; i < n; i++){
    while(n > 0){
        int digit = n%10;
        storage.push_back(digit);
        n= n/10;
    }
    
}

BigInt::~BigInt(){
    this->storage.clear();
}

BigInt::BigInt(BigInt const &n)
{
    storage = n.storage;
    it = storage.begin();
    rit = storage.rbegin();
    
}

int BigInt::size()
{
    return storage.size();
}

int BigInt:: next(){
    int current = *it;
    if(it < storage.end()){
        it++;
        return current;
    }
    return 0;
}

BigInt BigInt::operator++(int){
    BigInt temp(*this);
    *this = *this + 1;
    return temp;
    
}


BigInt BigInt::operator+(BigInt n){
    BigInt left(*this);
    BigInt right(n);
    BigInt result(0);
    result.storage.clear();
    
    int overhead = 0;
    int longest = (left.size() > right.size()) ? left.size():right.size();
    
    for (int counter = 0; counter < longest; counter++) {
        int x = left.next();
        int y = right.next();
        
        int storage = x + y + overhead;
        
        if(storage > 9){
            overhead = 1;
            result.storage.push_back(storage%10);
        }
        else{
            overhead = 0;
            result.storage.push_back(storage);
        }
    }
    if (overhead == 1) {
        result.storage.push_back(1);
    }
    return result;

}

BigInt BigInt:: operator + (int n){
    BigInt left(*this);
    BigInt right(n);
    return left + right;
}

BigInt BigInt:: operator - (BigInt n){
    BigInt left(*this);
    BigInt right(n);
    BigInt result(0);
    if(n > *this)return result;
    result.storage.clear();
    
    int overhead = 0;
    
    for (int counter = 0; counter < left.storage.size(); counter++) {
        int x = left.next();
        int y = right.next() + overhead;
        
        if(y > x){
            x += 10;
            overhead = 1;
        }
        else overhead = 0;
        
        int storage = x - y;
        result.storage.push_back(storage);
        
    }
    
    return result;
}

BigInt operator +(int n, BigInt N){
    return (N + n);
}



BigInt BigInt:: operator*(const BigInt &n){
    const int prodsize = n.storage.size() + storage.size() + 1;
    BigInt temp(0);
    temp.storage.resize(prodsize);
    unsigned long int x;
    int iplusj;
    for (int i = 0; i < storage.size();i++){
        for (int j = 0; j < n.storage.size(); j++){
            x = n.storage[j] * storage[i];
            iplusj = i + j;
            temp.storage[iplusj] += x %10;
            temp.storage[iplusj + 1] = temp.storage[iplusj]/10 + x / 10 +temp.storage[iplusj + 1];
            temp.storage[iplusj] %= 10;
        }
    }
    for(int g = temp.storage.size()-1;g >=0; g--){
        if (temp.storage[g] == 0)
            temp.storage.pop_back();
        else if(temp.storage[g]>0)
            break;
    }
    return temp;
}

BigInt BigInt:: operator *= (const BigInt  &n){
    return (*this = (*this) * n);
}

bool BigInt:: operator == (BigInt n){
    return ( storage == n.storage);
}

bool BigInt:: operator > (BigInt n){
    BigInt right(n);
    int longest = size() < n.size() ? n.size():size();
    bool isleftBigger = false;
    for (int i = 0; i < longest; i++) {
        int left = next();
        int right = n.next();
        if(left > right){
            isleftBigger = true;
        }
        else isleftBigger = false;
    }
    if(isleftBigger)return true;
    else return false;
}

bool BigInt:: operator < (BigInt n){
    //return (*(this) > n);
    vector<int>::reverse_iterator it = storage.rbegin();
    vector<int>::reverse_iterator rit = n.storage.rbegin();
    if(storage.size() < n.storage.size())
        return true;
    else if (storage.size() > n.storage.size())
        return false;
    else
        for(it = storage.rbegin(); it != storage.rend(); ++ it){
            if(*(it)<*(rit))
                return true;
            else if (*(it) > *(rit))
                return false;
            rit++;
        }
    return false;
}


ostream &operator <<(ostream &out,const BigInt  &n)
{
    BigInt temp(n);
    std::vector<int>::reverse_iterator rit;
    for (rit = temp.storage.rbegin(); rit < temp.storage.rend(); ++rit) {
        out << *rit;
    }
    return out;
}

void BigInt::print(){
    vector<int>::reverse_iterator rit;
    rit = storage.rbegin();
    while(rit!= storage.rend( ))
        cout<<*rit++;
}
