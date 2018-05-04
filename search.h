#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

using namespace std;

class Search {
  //returns index of val, or -1 if num not found
public:
  template<typename T, typename A> 
	  static int binarySearch(T val, vector<T,A> const& objects);
  template<typename T, typename A> 
	  static int linearSearch(T val, vector<T,A> const& objects);
  
};

#endif
