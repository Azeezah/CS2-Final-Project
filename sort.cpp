#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include "sort.h"
using namespace std;

template<typename T, typename A>
void Sort::Merge(vector<T, A> const& list, int i, int j, int k) {
    int mergedSize = k - i + 1;                // Size of merged partition
    int mergePos = 0;                          // Position to insert merged number
    int leftPos = 0;                           // Position of elements in left partition
    int rightPos = 0;                          // Position of elements in right partition
    T* mergedNumbers = new T[mergedSize];  // Dynamically allocates temporary array
    // for merged numbers
    
    leftPos = i;                               // Initialize left partition position
    rightPos = j + 1;                          // Initialize right partition position
    
    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (list[leftPos] < list[rightPos]) {
            mergedNumbers[mergePos] = list[leftPos];
            ++leftPos;
        }
        else {
            mergedNumbers[mergePos] = list[rightPos];
            ++rightPos;
            
        }
        ++mergePos;
    }
    
    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = list[leftPos];
        ++leftPos;
        ++mergePos;
    }
    
    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = list[rightPos];
        ++rightPos;
        ++mergePos;
    }
    
    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        list[i + mergePos] = mergedNumbers[mergePos];
    }
}

template<typename T, typename A>
void Sort::MergeSort(vector<T, A> const& list, int i, int k) {
    int j = 0;
    if (i < k) {
        j = (i + k) / 2;  // Find the midpoint in the partition
        
        // Recursively sort left and right partitions in place
        MergeSort(list, i, j);
        MergeSort(list, j + 1, k);
        
        // Merge left and right partition in sorted order
        Merge(list, i, j, k);
    }
}


