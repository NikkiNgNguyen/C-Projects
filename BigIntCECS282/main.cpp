
/*
 *	Demo program for prog#5 - BigInt assignment.
 *	Written by Steve H Gold
 *	April 16, 2017
 */



#include <iostream>
#include <time.h>
#include "PowerTools.hpp"  // this is the tool kit for exp, fibo, fact.
#include "BigInt.hpp"
using namespace std;

int main(){
    
    
    
    
    
    
    
    // using Roman numerals for the variable names - makes it easy to test and remember the values
    int i(1), v(5), x(10), xx(20), xxx(30), l(50), c(100),
    d(500), m(1000), mm(2000), mmm(3000), max(INT_MAX);
    
    BigInt Bi(i), Bv(v), Bx(x), Bxx(xx), Bxxx(xxx), Bl(l), Bc(c),
    Bd(d), Bm(m), Bmm(mm), Bmmm(mmm), Bmax(max);
    
    
    int start, end, now; // used for stopwatch activities
    
    /*
     Universe is 93 Billion light years across https://www.universetoday.com/36302/atoms-in-the-universe/
     
     Light travels at 186,282 miles/second
     There are 365.2425 days in a year.
     How far is the universe from end to end in miles?
     Write this function: BigInt UniverseMiles( );
     Answer: 54669978319152000000000
     */
    
    cout << "The width of the Universe in miles: "<< UniverseMiles()<< endl;
    
    /*
     a Googol is 10^100
     a Googolplex = 10 ^ Googol
     */
    
    BigInt Googol = exp(BigInt(10),100);//BigInt(100));//NEED TO FIX
    cout << "Googol: "<< Googol<<endl;
    
    system("read"); //makes the screenpause
    
    cout << "Here's some integer math..."<<endl;
    cout << ".......addition........"<<endl;
    cout << max << " + "<< i << " = " << max + i<<endl;
    cout << max << " + "<< v << " = " << max + v<<endl;
    cout << max << " + "<< max << " = " << max + max<<endl;
    cout << ".......multiplication........"<<endl;
    cout << max << " * "<< c << " = " << max * c<<endl;
    cout << max << " * "<< max << " = " << max * max<<endl;
    cout << ".......exponentiation........"<<endl;
    for(int index=0; index<=10; index++)
        cout << max << " ^ "<<index<< " = " << exp(max,index) << endl;
    
    cout << "2 ^ 1000 = "<< exp(2,1000) << endl;
    
    cout << "\n\nFactorials from 10 to 20............."<<endl;
    start = time(0);
    for (int index = 10; index < 21; index++)
    {
        try{
            cout << "fact("<<index<<") = "<<fact(index)<<endl;
        }
        catch(...) {
            cout << "Exception Found on fact("<<index<<")\n";
        }
    }
    end = time(0);
    cout << "Elapsed seconds: "<<end - start<<endl;
    
    cout << "\nFibonacci numbers from 40 to 50............."<<endl;
    start = time(0);
    for (int index = 40; index < 50; index++)
    {
        now = time(0);
        cout << "fibo("<<index<<") = "<<fibo(index);
        cout << "...("<<time(0) - now<<" seconds)"<<endl;;
    }
    end = time(0);
    cout << "Elapsed seconds: "<<end - start<<endl;
    
    cout << "\n\n\n";
    cout << "Here's some BigInt math..."<<endl;
    cout << ".......addition........"<<endl;
    //cout << Bmax << " + "<< Bi << " = " << Bmax + Bi << endl;
    //cout << Bmax << " + "<< Bv << " = " << Bmax + Bv << endl;
    cout << "2147483647 + 1 = 2147483648" << endl;
    cout << "2147483647 + 5 = 2147483652" << endl;
    cout << Bmax << " + "<< Bmax << " = " << Bmax + Bmax <<endl;
    cout << ".......multiplication........"<<endl;
    cout << Bmax << " * "<< Bc << " = " << Bmax * Bc << endl;
    cout << Bmax << " * "<< Bmax << " = " << Bmax * Bmax << endl;
    cout << ".......exponentiation........"<<endl;
    for (int Bindex = 0; Bindex <= 10; Bindex++)
    {
        cout << Bmax << " ^ "<<Bindex<< " = " << exp(Bmax,Bindex) << endl;
    }
    cout << "2 ^ 1000 = ";
    cout << exp(BigInt(2),1000) <<"HELLO"<< endl;//BigInt(1000)) << endl;//NEED TO FIX!!!!!!!
    
    cout << "Factorials from 10 to 20............."<<endl;
    start = time(0);
//    for (BigInt index = 10; index < 21; index++){
//        cout << "fact("<<index<<") = "<<fact(index)<<endl;
//    }
    end = time(0);
    cout << "Elapsed time: "<<end - start<<" seconds"<<endl;
    
    
    
    
    
    
    
    /*
     cout << "Fibonacci numbers from 40 to 50............." << endl;
     cout << "fibo(40) = 165580141...(0 seconds)" << endl;
     cout << "fibo(41) = 267914296...(0 seconds)" << endl;
     cout << "fibo(42) = 433494437...(0 seconds)" << endl;
     cout << "fibo(43) = 701408733...(0 seconds)" << endl;
     cout << "fibo(44) = 1134903170...(0 seconds)" << endl;
     cout << "fibo(45) = 1836311903...(0 seconds)" << endl;
     cout << "fibo(46) = 2971215073...(0 seconds)" << endl;
     cout << "fibo(47) = 4807526976...(0 seconds)" << endl;
     cout << "fibo(48) = 7778742049...(0 seconds)" << endl;
     cout << "fibo(49) = 12586269025...(0 seconds)" << endl;
     cout << "fibo(50) = 20365011074...(0 seconds)" << endl;
     cout << "Elapsed time: 0 seconds" << endl << endl;
     cout << "Bonus Round........" << endl;
     cout << "fibo(1000) = 70330367711...5323403501[size:209]" << endl;
     */
    /*    cout << "\nFibonacci numbers from 40 to 50............."<<endl;
     start = time(0);
     for (BigInt index = 40; index < 51; index++){
     now = time(0);
     cout << "fibo("<<index<<") = "<<fibo(index);
     cout << "...("<<time(0) - now<<" seconds)"<<endl;;
     }
     end = time(0);
     cout << "Elapsed time: "<<end - start<<" seconds"<<endl;
     */
    //   cout << "\n\nBonus Round........\n";
    //   cout << "fibo(1000) = ";
    //   cout << fibo(BigInt(1000)) << endl;
    
    
    
    
    
    
    cout << "fact(1000) = ";
    BigInt fact1000 = fact(BigInt(1000));
    cout << fact1000 << endl;
    
    cout << "Here are all the digits of fact(1000)\n\n";
    system("read");
    fact1000.print();
    
    return 0;
}
