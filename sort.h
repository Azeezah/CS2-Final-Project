//
//  sort.h
//  Sort
//
//  Created by Samantha-Jo Cunningham on 5/5/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#ifndef SORT_h
#define SORT_h

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;

class Sort { //sort class
public:
    template<typename TheType>
    static void MergeSort(TheType playlist, int i, int k);
    template<typename TheType>
    static void Merge(TheType playlist, int i, int j, int k);
};



#endif /* sort_h */
