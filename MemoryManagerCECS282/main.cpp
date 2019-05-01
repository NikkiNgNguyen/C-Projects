// Project 6 – Memory Manager
// Final Project main.cpp
/* Nikki Nguyen
 CECS 282 - Prog 6
 Steve Gold
 May 11, 2017*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS // allow Microsoft Visual C++ to user strcpy insted of strcpy_s
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <iomanip>

#include "MemoryManager.hpp"

struct simpleDate {
    short date[3];
};

void printSimpleDate(simpleDate * sdPtr)
{
    std::cout << *(short *)((char *)sdPtr + 0);
    std::cout << '/';
    std::cout << *(short *)((char *)sdPtr + 2);
    std::cout << '/';
    std::cout << *(short *)((char *)sdPtr + 4);
}

void setSimpleDate(simpleDate * sdPtr, int m, int d, int y)
{
    short * month = (short *) ((char *) sdPtr + 0);
    short * day = (short *) ((char *) sdPtr + 2);
    short * year = (short *) ((char *) sdPtr + 4);
    * month = (short) m;
    * day = (short) d;
    * year = (short) y;
}

int main(void)
{
    using namespace MemoryManager;  // allow functions in Memory Manager to be used without prefix
    initializeMemoryManager();
    
    int start = freeMemory();
    
    std::cout << "\nMem before any allocations\n";
    std::cout << "Free Memory:\t"<<freeMemory()<<std::endl;
    std::cout << "InUse Memory:\t"<<inUseMemory()<<std::endl;
    std::cout << "Used Memory:\t"<<usedMemory()<<std::endl;
    //	memView(0, 60);
    //	std::cin.get();
    
    //allocate some memory
    
    simpleDate* birthDayPtr = (simpleDate *) allocate(sizeof(simpleDate));
    std::cout << "\nMem after allocation of birthDay\n";
    std::cout << "size(birthDayPtr) = "<<size(birthDayPtr)<<std::endl;
    std::cout << "Free Memory:\t"<<freeMemory()<<std::endl;
    std::cout << "InUse Memory:\t"<<inUseMemory()<<std::endl;
    std::cout << "Used Memory:\t"<<usedMemory()<<std::endl;
    //	memView(0, 60);
    //	std::cin.get();
    
    char* gradePtr = (char*)allocate(sizeof(char));
    std::cout << "\nMem after allocation of gradePtr:\n";
    std::cout << "size(gradePtr) = "<<size(gradePtr)<<std::endl;
    std::cout << "Free Memory:\t"<<freeMemory()<<std::endl;
    std::cout << "InUse Memory:\t"<<inUseMemory()<<std::endl;
    std::cout << "Used Memory:\t"<<usedMemory()<<std::endl;
    //	memView(0, 60);
    //	std::cin.get();
    
    int* IDPtr = (int*)allocate(sizeof(int));
    std::cout << "\nMem after allocation of IDPtr:\n";
    std::cout << "size(IDPtr) = "<<size(IDPtr)<<std::endl;
    std::cout << "Free Memory:\t"<<freeMemory()<<std::endl;
    std::cout << "InUse Memory:\t"<<inUseMemory()<<std::endl;
    std::cout << "Used Memory:\t"<<usedMemory()<<std::endl;
    //	memView(0, 60);
    //	std::cin.get();
    
    char* name = (char*)allocate(15);
    std::cout << "\nMem after allocation of name:\n";
    std::cout << "size(name) = "<<size(name)<<std::endl;
    std::cout << "Free Memory:\t"<<freeMemory()<<std::endl;
    std::cout << "InUse Memory:\t"<<inUseMemory()<<std::endl;
    std::cout << "Used Memory:\t"<<usedMemory()<<std::endl;
    //	memView(0, 60);
    //	std::cin.get();
    
    std::cout << "\nMem after all allocations, before assignments\n";
    
    //	memView(0, 60);
    //	std::cin.get();
    
    *gradePtr = 'A';
    setSimpleDate(birthDayPtr, 5, 11, 2017);
    *IDPtr = 123456789;
    strcpy(name, "Master Gold");
    
    //	std::cout << "\nMem after all allocations, after assignments\n";
    
    //	memView(0, 60);
    //	system("pause");
    
    std::cout << std::endl;
    
    std::cout << "gradePtr    :" << " Address:" << (unsigned long*)gradePtr << " Value:"<<*gradePtr<<std::endl;
    
    std::cout << "birthDayPtr :" << " Address:" << (unsigned long*)(short *)birthDayPtr << " Value:";
    printSimpleDate (birthDayPtr);
    std::cout << std::endl;
    
    std::cout << "IDPtr       :"<<" Address:" << (unsigned long*)IDPtr << " Value:"<< *IDPtr<<std::endl;
    std::cout << "name        :"<<" Address:" << (unsigned long*)name << " Value:"<< name<<std::endl;
    
    std::cout << "\nDeallacting IDptr:"<<std::endl;
    deallocate(IDPtr);
    
    std::cout << "\nDeallacting gradePtr:"<<std::endl;
    deallocate(gradePtr);
    //	memView(0, 60);
    //	std::cout << "Press any key to continue:";
    //	std::cin.get();
    
    
    std::cout << "\nLeaking some Memory...\n";
    for(int i=0; i<5000; i++)
        int *memLeak = (int *) allocate(4);
    
    //	std::cout << "\nMem after Deallocations\n"<<std::endl;
    //	memView(0, 60);
    
    std::cout << "\n\nFree memory at start = " << start << std::endl;
    std::cout << "\n\nFree memory now = " << freeMemory() << std::endl;
    std::cout << "\n\nTotal Memory used = " << start - freeMemory() << std::endl;
    std::cout << "inUse Memory:\t"<<inUseMemory()<<std::endl;
    std::cout << "used Memory:\t"<<usedMemory()<<std::endl;
    std::cout << "Total Memory:\t"<<inUseMemory()+freeMemory()+usedMemory()<<std::endl;
    
    std::cout << std::endl;
    printSimpleDate(birthDayPtr);
    std::cout << "...Happy Birthday "<<name<<"!!!\n\n"<<std::endl;
    // force the screen to pause
    std::cout << "Press any key to continue:"<<std::endl;
    std::system("read");
    std::cin.get();
    
}
//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS // allow Microsoft Visual C++ to user strcpy insted of strcpy_s
//#endif
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdarg.h>
//#include <iostream>
//#include <iomanip>
//
//#include "MemoryManager.hpp"

//int main(void)
//{
//    using namespace MemoryManager;  // allow functions in Memory Manager to be used without prefix
//    
//    std::cout << "Overview of how big thing are:\n";
//    std::cout << std::left << std::setw(15) << "Sizeof char:" << sizeof(char);
//    std::cout << std::left << std::setw(16) << " Sizeof char*:" << sizeof(char*) << std::endl;
//    
//    std::cout << std::left << std::setw(15) << "Sizeof short:" << sizeof(short);
//    std::cout << std::left << std::setw(16) << " Sizeof short*:" << sizeof(short*) << std::endl;
//    
//    std::cout << std::left << std::setw(15) << "Sizeof int:" << sizeof(int);
//    std::cout << std::left << std::setw(16) << " Sizeof int*:" << sizeof(int*) << std::endl;
//    
//    std::cout << std::left << std::setw(15) << "Sizeof long:" << sizeof(long);
//    std::cout << std::left << std::setw(16) << " Sizeof long*:" << sizeof(long*) << std::endl;
//    
//    std::cout << std::left << std::setw(15) << "Sizeof float:" << sizeof(float);
//    std::cout << std::left << std::setw(16) << " Sizeof float*:" << sizeof(float*) << std::endl;
//    
//    std::cout << std::left << std::setw(15) << "Sizeof double:" << sizeof(double);
//    std::cout << std::left << std::setw(16) << " Sizeof double*:" << sizeof(double*) << std::endl;
//    
//    initializeMemoryManager();
//    
//    int start = freeMemory();
//    
//    std::cout << "\nMem before any allocations\n";
//    std::cout << "Free Memory:"<<freeMemory()<<std::endl;
//    memView(0, 50);
//    
//    // allocate some memory
//    
//    char* charPtr = (char*)allocate(sizeof(char));
//    short* shortPtr = (short*) allocate(sizeof(short));
//    int* intPtr = (int*)allocate(sizeof(int));
//    char* name = (char*)allocate(11);
//    
//    std::cout << "\nMem after allocations, before assignments\n";
//    
//    memView(0, 50);
//    
//    *charPtr = 'A';
//    *shortPtr = 30000;
//    *intPtr = 2000000000;
//    strcpy(name, "Steve Gold");
//    
//    std::cout << std::endl;
//    
//    std::cout << "charPtr Value:"<<*charPtr<< " address:" << (long*)charPtr << std::endl;
//    std::cout << "shortPtr Value:" << *shortPtr<<" address:" << (long*)shortPtr << std::endl;
//    std::cout << "intPtr Value:"<< *intPtr<<" address:" << (long*)intPtr << std::endl;
//    std::cout << "name Value:"<< name<<" address:" << (long*)name << std::endl;
//    
//    std::cout << "\nMem after allocations, after assignments\n";
//    memView(0, 50);
//    
//    std::cout << "\n\nFree memory at start = " << start << std::endl;
//    std::cout << "\n\nFree memory now = " << freeMemory() << std::endl;
//    std::cout << "\n\nTotal Memory used = " << start - freeMemory() << std::endl;
//    
//    int a;
//    std::cin >> a;
//    
//}
//

