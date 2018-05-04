#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

class Search {
  //returns index of val, or -1 if num not found
  template<T> static T binarySearch(T value, vector<T> objects);
  template<T> static T linearSearch(T value, vector<T> objects);
};

#endif
