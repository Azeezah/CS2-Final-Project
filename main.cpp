#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;
class Sort {
public:
	static void SelectionSort(int numbers[], int numbersSize) {
		int i = 0;
		int j = 0;
		int indexSmallest = 0;
		int temp = 0;
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
	static void InsertionSort(int numbers[], int numbersSize) {
		int i = 0;
		int j = 0;
		int temp = 0;  // Temporary variable for swap

		for (i = 1; i < numbersSize; ++i) {
			j = i;
			// Insert numbers[i] into sorted part
			// stopping once numbers[i] in correct position
			while (j > 0 && numbers[j] < numbers[j - 1]) {

				// Swap numbers[j] and numbers[j - 1]
				temp = numbers[j];
				numbers[j] = numbers[j - 1];
				numbers[j - 1] = temp;
				--j;
			}
		}
		cout << "i: " << i << ", j: " << j << endl;
		cout << "temp: " << temp << endl;
		return;
	}
	static void Merge(int numbers[], int i, int j, int k) {
		int mergedSize = k - i + 1;                // Size of merged partition
		int mergePos = 0;                          // Position to insert merged number
		int leftPos = 0;                           // Position of elements in left partition
		int rightPos = 0;                          // Position of elements in right partition
		int* mergedNumbers = new int[mergedSize];  // Dynamically allocates temporary array
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
	static void MergeSort(int numbers[], int i, int k) {
		int j = 0;

		if (i < k) {
			j = (i + k) / 2;  // Find the midpoint in the partition

							  // Recursively sort left and right partitions
			MergeSort(numbers, i, j);
			MergeSort(numbers, j + 1, k);

			// Merge left and right partition in sorted order
			Merge(numbers, i, j, k);
		}
	}
};

int main() {
	Sort obj;
	int numbers[] = { 10, 6, 3, 89, 2, -1, 5 };
	const int NUMBERS_SIZE = 7;
	int i = 0;
	for (i = 0; i < NUMBERS_SIZE; ++i) {
		cout << numbers[i] << ' ';
	}
	cout << endl;
	cout << "\n\nSelection Sort: " << endl;
	obj.SelectionSort(numbers, NUMBERS_SIZE);
	for (i = 0; i < NUMBERS_SIZE; ++i) {
		cout << numbers[i] << ' ';
	}
	cout << endl;

	cout << "\n\nInsertion Sort: " << endl;
	int number[] = { 10, 6, 3, 89, 2, -1, 5 };
	obj.InsertionSort(number, NUMBERS_SIZE);
	for (i = 0; i < NUMBERS_SIZE; ++i) {
		cout << number[i] << ' ';
	}
	cout << endl;

	cout << "\n\nMerge Sort: " << endl;
	
	int num[] = { 100, 6, -23, 89, 2, -1, 5 };
	Sort::MergeSort(num,0,NUMBERS_SIZE-1);
	for (i = 0; i < NUMBERS_SIZE; ++i) {
		cout << num[i] << ' ';
	}
	cout << endl;

	return 0;
}
