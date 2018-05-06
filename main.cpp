//
//  main.cpp
//  FinalProject
//
//  Created by Samantha-Jo Cunningham on 5/5/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;
#include "sort.h"

int main() {
    vector <string> playlist; //vector playlist
    int vect_Length = sizeof(playlist)/sizeof(playlist[0]); //length of the playlist
    
    
    cout << "***Sorted Playlist" << endl << endl;
    Sort::MergeSort(playlist, 0, vect_Length - 1); //calls the mergesort function
    for (int i = 0; i < vect_Length; i++) {
        cout << playlist[i] << '\t'; //prints sorted playlist
    }
    cout << endl << endl;
    
    return 0;
}

