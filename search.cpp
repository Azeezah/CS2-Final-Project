#include <iostream>
#include <vector>
#include "search.h"

using namespace std;

T Search::binarySearch(T val, vector<T> objects) {
	int min = 0, max = nums.size() - 1; 
	while (max >= min) {
		if (objects[(max+min)/2] < val) { 
			min = (max+min)/2 + 1; 
		} else if (objects[(max + min)/2] > val) { 
			max = (max+min)/2 - 1; 
		} else { 
			return (max+min)/2; 
		} 
	} 
	return -1; // not found 
}


T Search::linearSearch(T val, vector<T> objects){
  for(int i=0; i<objects.size(); i++){
    if(objects.at(i)==val) return i;
  }
  return -1;
}

