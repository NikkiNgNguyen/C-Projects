#ifndef _POWERTOOLS
#define _POWERTOOLS

#include "BigInt.hpp"
#include <iostream>

int fibo(int n);
int fact(int n);
int exp(int x, int y);
BigInt UniverseMiles();

BigInt fibo(BigInt Bx);
BigInt fact(BigInt Bx);
BigInt exp(BigInt Bx , BigInt By);
BigInt exp(BigInt Bx, int y);



#endif
