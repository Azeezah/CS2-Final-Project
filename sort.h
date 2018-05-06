//
//  sort.h
//  Sort
//
//  Created by Samantha-Jo Cunningham on 5/5/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;

class Sort { //cort class
public:
    template<typename TheType>
    static void MergeSort(TheType playlist, int i, int k);
    template<typename TheType>
    static void Merge(TheType playlist, int i, int j, int k);
};
template<typename TheType>
void Sort::Merge(TheType playlist, int i, int j, int k) {
    int mergedSize = k - i + 1;                // Size of merged partition
    int mergePos = 0;                          // Position to insert merged number
    int leftPos = 0;                           // Position of elements in left partition
    int rightPos = 0;                          // Position of elements in right partition
    TheType* mergedNumbers = new TheType[mergedSize];  // Dynamically allocates temporary array
    // for merged numbers
    
    leftPos = i;                               // Initialize left partition position
    rightPos = j + 1;                          // Initialize right partition position
    
    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (playlist[leftPos] < playlist[rightPos]) {
            mergedNumbers[mergePos] = playlist[leftPos];
            ++leftPos;
        }
        else {
            mergedNumbers[mergePos] = playlist[rightPos];
            ++rightPos;
            
        }
        ++mergePos;
    }
    
    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = playlist[leftPos];
        ++leftPos;
        ++mergePos;
    }
    
    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = playlist[rightPos];
        ++rightPos;
        ++mergePos;
    }
    
    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        playlist[i + mergePos] = mergedNumbers[mergePos];
    }
}
template<typename TheType>
void Sort::MergeSort(TheType playlist, int i, int k) {
    int j = 0;
    if (i < k) {
        j = (i + k) / 2;  // Find the midpoint in the partition
        
        // Recursively sort left and right partitions
        MergeSort(playlist, i, j);
        MergeSort(playlist, j + 1, k);
        
        // Merge left and right partition in sorted order
        Merge(playlist, i, j, k);
    }
}


#endif /* sort_h */
