#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;
class Sort{
public:
	template<typename T>
static void SelectionSort(T numbers[], int numbersSize) {
		int i = 0;
		int j = 0;
		int indexSmallest = 0;
		T temp;
		for (i = 0; i < numbersSize - 1; ++i) {
			indexSmallest = i;
			for (j = i + 1; j < numbersSize; ++j) {
				if (numbers[j] < numbers[indexSmallest]) {
					indexSmallest = j;
				}
			}
			temp = numbers[i];
			numbers[i] = numbers[indexSmallest];
			numbers[indexSmallest] = temp;
		}
		cout << "i: " << i << ", j: " << j << endl;
		cout << "temp: " << temp << ", indexSmallest: " << indexSmallest << endl;
	}
template<typename T>
static void InsertionSort(T numbers[], int numbersSize) {
		int i = 0;
		int j = 0;
		T temp;  // Temporary variable for swap

		for (i = 1; i < numbersSize; ++i) {
			j = i;
			// Insert numbers[i] into sorted part
			// stopping once numbers[i] in correct position
			while(j > 0 && numbers[j] < numbers[j - 1]) {
				cout << "In while" << endl;
				// Swap numbers[j] and numbers[j - 1]
				temp = numbers[j];
				numbers[j] = numbers[j - 1];
				numbers[j - 1] = temp;
				--j;
			}
		}
		cout << "i: " << i << ", j: " << j << endl;
		return;
	}
template<typename T>
static void Merge(T numbers[], int i, int j, int k) {
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
			if (numbers[leftPos] < numbers[rightPos]) {
				mergedNumbers[mergePos] = numbers[leftPos];
				++leftPos;
			}
			else {
				mergedNumbers[mergePos] = numbers[rightPos];
				++rightPos;

			}
			++mergePos;
		}

		// If left partition is not empty, add remaining elements to merged numbers
		while (leftPos <= j) {
			mergedNumbers[mergePos] = numbers[leftPos];
			++leftPos;
			++mergePos;
		}

		// If right partition is not empty, add remaining elements to merged numbers
		while (rightPos <= k) {
			mergedNumbers[mergePos] = numbers[rightPos];
			++rightPos;
			++mergePos;
		}

		// Copy merge number back to numbers
		for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
			numbers[i + mergePos] = mergedNumbers[mergePos];
		}
	};
template<typename T>
static void MergeSort(T numbers[], int i, int k) {
		int j = 0;

		if (i < k) {
			j = (i + k) / 2;  // Find the midpoint in the partition

							  // Recursively sort left and right partitions
			MergeSort(numbers, i, j);
			MergeSort(numbers, j + 1, k);

			// Merge left and right partition in sorted order
			Merge(numbers, i, j, k);
		}
};
};

int main() {
	
	int numbers[] = { 7,98,6,-5,1};
	string words[] = {"yapple", "Yapple", "BABBLE", "apple"};
	int nsize = 5;
	int wsize = 4;
	
	int i = 0;
	for (i = 0; i < wsize; ++i) {
		cout << words[i] << ' ';
	}
	cout << endl;
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
	
	cout << "\n\nMerge Sort: " << endl;
	Sort::MergeSort(numbers, 0, nsize - 1);
	for (i = 0; i < nsize; ++i) {
		cout << numbers[i] << ' ';
	}
	cout << endl;
	cout << "\n\nMerge Sort: " << endl;
	Sort::MergeSort(words, 0, wsize - 1);
	for (i = 0; i < wsize; ++i) {
		cout << words[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
