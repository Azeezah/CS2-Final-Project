#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
#include<vector>
#include<algorithm>
#include "sort.h"

using namespace std;

int main() {	
	vector<int> numbers = { 7,98,6,-5,1};
	vector<string> words = {"yapple", "Yapple", "BABBLE", "apple"};
	int nsize = 5;
	int wsize = 4;
	
	int i = 0;
	for (i = 0; i < wsize; ++i) {
		cout << words[i] << ' ';
	}
	cout << endl;
	/*
	cout << "\n\nSelection Sort: " << endl;
	Sort::SelectionSort(words, wsize);
	for (i = 0; i < wsize; ++i) {
		cout << words[i] << ' ';
	}
	cout << endl;
	cout << "\n\nSelection Sort: " << endl;
	Sort::SelectionSort(numbers, nsize);
	for (i = 0; i < nsize; ++i) {
		cout << numbers[i] << ' ';
	}
	cout << endl;
	
	cout << "\n\nInsertion Sort: " << endl;
	Sort::InsertionSort(numbers, nsize);
	for (i = 0; i < nsize; ++i) {
		cout << numbers[i] << ' ';
	}
	cout << endl;
	cout << "\n\nInsertion Sort: " << endl;
	Sort::InsertionSort(words, wsize);
	for (i = 0; i < wsize; ++i) {
		cout << words[i] << ' ';
	}
	cout << endl;
	*/
	int zero = 0;
	cout << "\n\nMerge Sort: " << endl;
	Sort::MergeSort(numbers, zero, nsize - 1);
	for (i = 0; i < nsize; ++i) {
		cout << numbers[i] << ' ';
	}
	cout << endl;
	cout << "\n\nMerge Sort: " << endl;

	Sort::MergeSort(words, zero, wsize - 1);
	for (i = 0; i < wsize; ++i) {
		cout << words[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
