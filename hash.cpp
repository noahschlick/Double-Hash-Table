//
//  hash.cpp
//  Project4_Hash
//
//  Created by Noah Schlickeisen on 4/22/21.
//  CS 3358 Data Structures and Algorithms (Section 3358-256)
//
//
//  This file test the hash table data structure.
// It uses a random arrray to test insertion and
// sorting. It also test to make sure the hash table
// does not store duplicates.
//

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
// IMPOTANT MESSAGE: When compiling the program on Texas State school
// servers type in command//
//
//                  g++ Assign2_Q2.cpp -std=c++11
//                  ./a.out
//
// This will run the orject on the latest version of C++ to make the program
// effectively.
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

#include <iostream>
#include "hash.h"
using namespace std;

// function to check if hash table is full

int main()
{
    HashTable<int> hash(19, 5);
    
    int size = 20;
    int test4[size];
    int probe;
    bool contains;
    
    srand(time(NULL));
    int random;

    // Test using an arrray of random numbers
    for(int i = 0; i < size; i++)
    {
        random = 0 + rand() % (70);
        test4[i] = random;
    }
    
    cout << "Random array is: ";
    
    for (int i = 0; i < size; i++)
    {
        cout << test4[i] << " ";
    }
    cout << endl;
    
    
    for(int i = 0; i < size; i++)
    {
        probe = hash.Insert(test4[i]);
        cout << "Inserting " << test4[i] << "   ";
        cout << "Number of probes is " << probe << "    " << endl;
    }
    
    cout << "Random hash is: ";
    hash.Print();
    
    for(int i = 0; i < 20; i++)
    {
        cout << "Searching " << i << "   ";
        contains = hash.Contains(i);
        if (contains == 1)
            cout << i << " is present";
        else
            cout << i << " is absent";
        cout << endl;
    }
    
    cout << endl;
 
    // Test in a case where there are duplicates
    HashTable<int> hash2(19, 5);
    
    for(int i = 0; i < size; i++)
    {
        
        test4[i] = 1;
    }
    
    cout << "Array is: ";
    
    for (int i = 0; i < size; i++)
    {
        cout << test4[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < size; i++)
    {
        probe = hash2.Insert(test4[i]);
        cout << "Inserting " << test4[i] << "   ";
        cout << "Number of probes is " << probe << "    " << endl;
    }
    
    cout << "Hash is: ";
    hash2.Print();
}
