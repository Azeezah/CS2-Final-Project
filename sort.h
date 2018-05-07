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
    template<typename T, typename A>
    static void MergeSort(vector<T, A> const& list, int i, int k);
    template<typename T, typename A>
    static void Merge(vector<T, A> const& list, int i, int j, int k);

};



#endif /* sort_h */
