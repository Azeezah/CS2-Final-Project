#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include<algorithm>
#include<vector>
using  namespace std;
class Stack {
public:
	void Push(int num) {
		Svec.push_back(num);
	}
	int Pop() {
		int top;
		top = Svec.back();
		Svec.pop_back();
		return top;
		
	}
	void Print() {
		for (int i = 0;i < Svec.size();i++) {
			cout << Svec[i] << " ";
		}
	}
	void fillStack(ifstream &file1, string filename) {
		int num;
		file1.open(filename);
		file1 >> num;
		while (!file1.eof()) {
			Push(num);
			file1 >> num;
		} cout << "All numbers pushed onto stack" << endl;
		file1.close();
	}
	void SSort() {
		sort(Svec.begin(), Svec.end());
	}
	void SRevSort() {
		reverse(Svec.begin(), Svec.end());
	}
	int BinarySearch(int key) {
		int mid = 0;
		int low = 0;
		int high = 0;
		high = Svec.size();
		while (high >= low) {
			mid = (high + low) / 2;
			if (Svec[mid] < key) {
				low = mid + 1;
			}
			else if (Svec[mid] > key) {
				high = mid - 1;
			}
			else {
				return mid;
			}
		}
		return -1;
	}
	int LinearSearch(int search_val) {
		int index = -1;
		cout << "The index for the number " << search_val;
		for (int a = 0;a < Svec.size();a++) {
			if (Svec.at(a) == search_val) {
				index = a;
			}
		}
		if (index != -1) {
			cout << " is " << index << endl;
			return index;
		}
		else {
			cout << " was not found." << endl;
			return index;
		}
	}
private:
	vector <int> Svec;
};
class Queue {
public:
	void Enqueue(int num) {
		Qvec.push_back(num);
	};
	int Dequeue() {
		int top_value = Qvec.at(0);
		vector<int>::iterator top=Qvec.begin();
		Qvec.erase(top);
		return top_value;
		
	};
	void Print() {
		for (int w = 0;w < Qvec.size();w++) {
			cout << Qvec[w] << " ";
		}
	}
	void fillQueue(ifstream &QQ, string filename) {
		int num;
		QQ.open(filename);
		while (!QQ.eof()) {
			QQ >> num;
			Enqueue(num);
		} cout << "All numbers enqueued" << endl;
		QQ.close();
	}
	void QSort() {
		sort(Qvec.begin(), Qvec.end());
	}
	void QRevSort() {
		reverse(Qvec.begin(), Qvec.end());
	}
	int BinarySearch(int key) {
		
		int mid = 0;
		int low = 0;
		int high = 0;
		high = Qvec.size();
		while (high >= low) {
			mid = (high + low) / 2;
			if (Qvec[mid] < key) {
				low = mid + 1;
			}
			else if (Qvec[mid] > key) {
				high = mid - 1;
			}
			else {
				return mid;
			}
		}
		return -1;
	}
	int LinearSearch(int search_val) {
		int index = -1;
		cout << "The index for the number " << search_val;
		for (int a = 0;a < Qvec.size();a++) {
			if (Qvec.at(a) == search_val) {
				index = a;
			}
		}
		if (index != -1) {
			cout << " is " << index << endl;
			return index;
		}
		else {
			cout << " was not found." << endl;
			return index;
		}
	}
private:
	vector <int> Qvec;
};

ifstream file1, file2;
//ifstream sortfile1, sortfile2;

int main() {
	Stack s; Queue q;
	string filename = "list1.txt";
	s.fillStack(file1, filename);//Stack populated
	filename = "list2.txt";
	q.fillQueue(file2,filename);//Queue populated
	cout << "*********************" << endl;
	int search_val=0;
	try{
		cout << "Please enter the value you're searching: ";
		cin >> search_val;
		if(search_val<0){
			throw runtime_error("Positive numbers only.");
		}
	}
	catch(runtime_error &except){
		cout << except.what() << endl;
		cout << "There are no negative numbers. PLease run the program again"<<endl;
		return 0;
	}
	s.SSort();q.QSort();
	int index = s.LinearSearch(search_val);
	index = s.BinarySearch(search_val);
	if (index == -1) {
		cout << "This number was never found" << endl;
	}
	else {
		cout << "The index is " << index << endl;
	}
	index = q.LinearSearch(search_val);
	index = q.BinarySearch(search_val);
	if (index == -1) {
		cout << "This number was never found" << endl;
	}
	else {
		cout << "The index is " << index << endl;
	}
	
	cout << "\nStack:" << endl;
	s.Print();
	cout << "\nQueue:" << endl;
	q.Print();

	s.SRevSort();q.QRevSort();

	cout << "\nReversed Stack:" << endl;
	s.Print();
	cout << "\nReversed Queue:" << endl;
	q.Print();
	
	return 0;
}
/*
All numbers pushed onto stack
All numbers enqueued
*********************
The index for the number 12 is 23
The index is 22
The index for the number 12 was not found.
This number was never found

Stack:
1 2 3 3 3 3 3 4 4 4 5 6 6 7 7 8 10 10 11 11 11 11 12 12 13 14 16 16 16 17 18 18 18 19 19 19 21 21 22 22 22 24 25 25 25 25 26 26 26 28 28 28 29 29 29 29 30 30 31 31 31 33 33 34 34 34 34 34 34 35 35 35 35 37 37 37 40 41 41 42 43 43 43 43 44 44 44 44 45 47 47 47 47 49 49 49 49 50 50
Queue:
2 2 2 2 3 3 3 3 4 4 4 4 5 5 6 6 8 9 9 9 10 13 13 13 14 14 14 14 15 16 16 16 17 17 18 19 19 20 21 21 22 23 23 25 25 25 26 27 27 28 28 29 29 31 31 32 32 33 33 33 33 33 34 34 34 34 34 36 36 37 38 38 39 40 40 40 41 41 41 42 43 43 43 43 43 43 44 44 45 46 46 46 47 47 48 48 49 50 50 50
Reversed Stack:
50 50 49 49 49 49 47 47 47 47 45 44 44 44 44 43 43 43 43 42 41 41 40 37 37 37 35 35 35 35 34 34 34 34 34 34 33 33 31 31 31 30 30 29 29 29 29 28 28 28 26 26 26 25 25 25 25 24 22 22 22 21 21 19 19 19 18 18 18 17 16 16 16 14 13 12 12 11 11 11 11 10 10 8 7 7 6 6 5 4 4 4 3 3 3 3 3 2 1
Reversed Queue:
50 50 50 49 48 48 47 47 46 46 46 45 44 44 43 43 43 43 43 43 42 41 41 41 40 40 40 39 38 38 37 36 36 34 34 34 34 34 33 33 33 33 33 32 32 31 31 29 29 28 28 27 27 26 25 25 25 23 23 22 21 21 20 19 19 18 17 17 16 16 16 15 14 14 14 14 13 13 13 10 9 9 9 8 6 6 5 5 4 4 4 4 3 3 3 3 2 2 2 2 Press any key to continue . . .

*/
