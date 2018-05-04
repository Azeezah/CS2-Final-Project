#include <iostream>
#include <vector>
#include "search.h"

using namespace std;

int main(){
	vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7};
	cout << nums[5] << endl;
	cout << "Index of 2 in nums vector: " << Search::linearSearch(2, nums) << endl;
	return 0;
}
