#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include "search.h"

using namespace std;

template<typename T, typename A>
int Search::binarySearch(T val, vector<T, A> const& objects) {
	int min = 0, max = objects.size() - 1;
	while (max >= min) {
		if (objects[(max + min) / 2] < val) {
			min = (max + min) / 2 + 1;
		}
		else if (objects[(max + min) / 2] > val) {
			max = (max + min) / 2 - 1;
		}
		else {
			return (max + min) / 2;
		}
	}
	return -1; // not found 
}

template<typename T, typename A>
int Search::linearSearch(T val, vector<T, A> const& objects) {
	for (int i = 0; i<objects.size(); i++) {
		if (objects.at(i) == val) return i;
	}
	return -1;
}
int main(){
	vector<string> nums = {"Well", "Waht", "Ahh", "Ummm", "Jah Know", "K den", "No dawg", "Woah"};
	sort(nums.begin(), nums.end());
	cout << nums[2] << endl; string k = "K den";
	cout << "Index of 2 in nums vector: " << Search::linearSearch(k, nums) << endl;
	return 0;
}