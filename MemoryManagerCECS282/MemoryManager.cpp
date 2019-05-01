//
//  MemoryManager.cpp
//  Prog6
//
//  Created by Nikki Nguyen on 5/10/17.
//  Copyright © 2017 Nikki Nguyen. All rights reserved.
//

#include "MemoryManager.hpp"

#include <iomanip>
#include <iostream>
using namespace std;

namespace MemoryManager
{
    // IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
    //
    // This is the only static memory that you may use, no other global variables
    // may be created, if you need to save data make it fit in MM_pool
    //
    // IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
    
    const int MM_POOL_SIZE = 65536;
    char MM_pool[MM_POOL_SIZE];
    
    // I have provided this tool for your use
    void memView(int start, int end)
    {
        const unsigned int SHIFT = 8;
        const unsigned int MASK = 1 << SHIFT - 1;
        
        unsigned int value;	// used to facilitate bit shifting and masking
        
        cout << "         Pool                     Unsignd  Unsigned " << endl;
        cout << "Mem Add  indx   bits   chr ASCII#  short      int    " << endl;
        cout << "-------- ---- -------- --- ------ ------- ------------" << endl;
        
        for (int i = start; i <= end; i++)
        {
            cout << (long*)(MM_pool + i) << ':';	// the actual address in hexadecimal
            cout << '[' << setw(2) << i << ']';		// the index into MM_pool
            
            value = MM_pool[i];
            cout << " ";
            for (int j = 1; j <= SHIFT; j++)	// the bit sequence for this byte (8 bits)
            {
                cout << ((value & MASK) ? '1' : '0');
                value <<= 1;
            }
            cout << " ";
            
            cout << '|' << *(char*)(MM_pool + i) << "| (";	// the ASCII character of the 8 bits (1 byte)
            cout << setw(4) << ((int)(*((unsigned char*)(MM_pool + i)))) << ")";// the ASCII number of the character
            
            cout << " (" << setw(5) << (*(unsigned short*)(MM_pool + i)) << ")";// the unsigned short value of 16 bits (2 bytes)
            cout << " (" << setw(10) << (*(unsigned int*)(MM_pool + i)) << ")";	// the unsigned int value of 32 bits (4 bytes)
            
            cout << endl;
        }
    } 
    
    // Initialize set up any data needed to manage the memory pool
    void initializeMemoryManager(void)
    {
        // your solution goes here
        //int MAX_SIZE = 256;
        *(unsigned short*) MM_pool = 6; //next free memory index
        *(unsigned short*) (MM_pool + 2) = 0; //InUse Head - allocated stuff
        *(unsigned short*) (MM_pool + 4) = 0; //Used Head - deallocated stuff
//        *(unsigned short*) MM_pool = 4; //next free memory index
//        *(unsigned short*) (MM_pool + 4) = 65532; //Used Head - deallocated stuff
       
    }
    
    // Return a pointer inside the memory pool
    // If no chunk can accommodate aSize call onOutOfMemory()
    void* allocate(int aSize)
    {
        // your solution goes here
        //no memory to reallocate
        if((*MM_pool + aSize + 6) > (MM_POOL_SIZE-1))
        {
            onOutOfMemory();
            return 0;
        }
        unsigned short i = *(unsigned short*)MM_pool;
        unsigned short inUse = *(unsigned short*)(MM_pool + 2);
        *(unsigned short *)(MM_pool + i) = aSize;

        if(inUse != 0)
        {
            *(unsigned short *)(MM_pool + i + 2) = inUse;
            *(unsigned short *)(MM_pool + inUse + 4) = i;
        }
        *(unsigned short *)(MM_pool + 2) = i;
        *(unsigned short*)MM_pool = i + (6 + aSize);
        //return allocated memory
        return (void *)(MM_pool + i + 6);
    }
    
    // Free up a chunk previously allocated memory
    void deallocate(void* aPointer)
    {
        // your solution goes here
        unsigned short curr = (char*)(aPointer) - 6 - MM_pool;
        unsigned short prev = *(unsigned short*)(MM_pool + curr + 4);
        unsigned short next = *(unsigned short*)(MM_pool + curr + 2);
        unsigned short used = *(unsigned short*)(MM_pool + 4);
        if (next != 0)
            *(unsigned short*)(MM_pool + next + 4) = prev;
        if (prev != 0)
            *(unsigned short*)(MM_pool + prev + 2) = next;
        if(curr == *(unsigned short*)(MM_pool + 2))
            *(unsigned short*)(MM_pool + 2) = next;
        if (used != 0)
            *(unsigned short*)(MM_pool + used + 4) = curr;
        *(unsigned short*)((char*)(aPointer) - 4) = used;
        *(unsigned short*)(MM_pool + 4) = curr;
    }
    
    // Scan the memory pool and return the total free space remaining in bytes
    int freeMemory(void)
    {
        // your solution goes here
        return MM_POOL_SIZE - inUseMemory() - usedMemory() - 6;    }
    
    // Scan the memory pool and return the total deallocated memory in bytes
    int usedMemory(void)
    {
        // your solution goes here
        int counter = 0;
        int size = 0;
        unsigned short *curr = (unsigned short*)(MM_pool + *(unsigned short*)(MM_pool + 4));
        if (*(MM_pool + 4) == 0){
            return size;
        }
        else{
            while (true){
                size += *(curr);
                counter++;
                if (*(curr + 1) == 0){
                    break;
                }
                curr = (unsigned short*)(MM_pool + *(curr + 1));
            }
        }
        return size + counter * 6;
    }
    
    // Scan the memory pool and return the total in use memory
    int inUseMemory(void)
    {
        // your solution goes here
        int counter = 0;
        int size = 0;
        unsigned short *curr = (unsigned short*)(MM_pool + *(unsigned short*)(MM_pool + 2));
        
        if (*(unsigned short*)(MM_pool + 2) == 0)return size;
        else{
            while (true){
                size += *(curr);
                counter++;
                if (*(curr + 1) == 0)break;
                curr = (unsigned short*)(MM_pool + *(curr + 1));
            }
        }
        return size + counter * 6;
    }
    
    // Return the size (in bytes) associated with this memory address
    int size(void * aPointer)
    {
        // your solution goes here
        return *(unsigned short*)(void*)((char*)aPointer - 6);
    }
    
    // This is called when no more memory is available to allocate
    void onOutOfMemory(void)
    {
        std::cerr << "/nMemory pool out of memory" << std::endl;
        cin.get( );
        exit(1);
    }
}
