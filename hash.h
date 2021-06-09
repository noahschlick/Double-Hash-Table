//
//  hash.h
//  Project4_Hash
//
//  Created by Noah Schlickeisen on 4/22/21.
//  CS 3358 Data Structures and Algorithms (Section 3358-256)
//
//
// This file contain a double hashing data structure
// it contains methods that operate on the hash table
// including searching, outputing, and insertion.
//

#ifndef hash_h
#define hash_h

#include <iostream>


using namespace std;
template <typename T>

class HashTable
{
private:
    int *hashTable;
    int currentSize;
    int PRIME;
    int TABLE_SIZE;
public:
    
    // Returns false if program not full
    bool isFull()
    {
        return (currentSize == TABLE_SIZE);
    }

    // Returns value under first hash
    int hash1(int key)
    {
        return (key % TABLE_SIZE);
    }

    // Returns value under second hash
    int hash2(int key)
    {
        return (PRIME - (key % PRIME));
    }


    // Constructor: Creates empty hash table
    // Also passes table size and a prime number
    // for the second hash.
    HashTable(int table_size, int prime)
    {
        hashTable = new int[table_size];
        currentSize = 0;
        PRIME = prime;
        TABLE_SIZE = table_size;
        for (int i = 0; i < table_size; i++)
            hashTable[i] = -1;
    }
    
    // Destructor: Deallocates hash table
    ~HashTable()
    {
        delete[] hashTable;
    }
    
    // The value and returns number of probes
    // during hashing process.
    int Insert(T);
    
    // Searches for givin value, returns true
    // if value found
    bool Contains(T);
    
    // Displays entire hash table
    void Print();
};


/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
Insert:
Inserts a value in to the hash table with double
hashing. The parameter is the value to be inserted
into the hash table=. The Method return the number
of time the value had to be probed into a area in
the hash table
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
template <typename T>
int HashTable<T>::Insert(T value)
{
    // if hash table is full
    if (isFull())
        return 0;
    
    // get index for first hash
    int index = hash1(value);
    
    // If the value already exist, return 1
    if (hashTable[index] == value)
        return 1;
    
    // if collision occurs
    if (hashTable[index] != -1)
    {
        // get Index for 2nd hash function
        int index2 = hash2(value);
        int i = 1;
        
        // iterate according to hash index until
        // empty space filled
        while (1)
        {
        // get Index for 2nd hash function
        int newIndex = (index + i * index2) % TABLE_SIZE;
            
            // If the values are the same return i
            if (hashTable[newIndex] == value)
                return i;
            
            // Fill the empty space
            if (hashTable[newIndex] == -1)
            {
                hashTable[newIndex] = value;
                currentSize++;
                return i;
            }
            i++;
        }
    }
    // If first hash is succesful
    else
    {
        hashTable[index] = value;
        currentSize++;
        return 1;
    }
}

/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
Contains:
Method that searches for a given value passed
through the parameter. Returns false if value
not found. Returns true is value is found.
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
template <typename T>
bool HashTable<T>::Contains(T value)
{
    int index1 = hash1(value);
    int index2 = hash2(value);
    int i = 0;
    
    // iterate using hash function to find value
    while (hashTable[(index1 + i * index2) % TABLE_SIZE] != value)
    {
        // If numbe not found, return false
        if (hashTable[(index1 + i * index2) % TABLE_SIZE] == -1 || i == TABLE_SIZE)
            return false;
        i++;
    }
    return true;
}

/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
Print:
Void funtion with no parameters that displays the
hash table in a readable fasion.
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
template <typename T>
void HashTable<T>::Print()
{
    // Display in readable fasion replacing
    // -1(empty slot) with "_ " empty slot
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] || hashTable[i] == 0)
        {
            if (hashTable[i] == -1)
                cout << "_ ";
            else
                cout << hashTable[i] << " ";
        }
    }
    cout << endl;
}


#endif /* hash_h */
