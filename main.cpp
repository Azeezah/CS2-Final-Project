//
//  main.cpp
//  lab04_17_2018
//
//  Created by Samantha-Jo Cunningham on 4/17/18.
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

class Stack {
private:
    vector<int> stackVect;
public:
    void Push(int num);
    int pop();
    void print();
    void LinearSearch(int num);
    int BinarySearch(int num);
};
class Queue {
private:
    vector<int> queueVect;
public:
    void Push(int num);
    int pop();
    void print();
    void LinearSearch(int num);
    int BinarySearch(int num);
    
};
void Stack::Push(int num) {
    stackVect.push_back(num);
    return;
};

int Stack::pop() {
    int firstIn = stackVect.back();
    stackVect.pop_back();
    return firstIn;
};

void Stack::print() {
    cout <<  "***STACK***" << endl;
    for (int i = stackVect.size() - 1; i > 0; i--){
        cout << stackVect.at(i) << endl;
    }
    cout << endl;
};

void Stack::LinearSearch(int num) {
    for (int i = 0; i < 100; i++){
        if(stackVect.at(i) == num) {
            cout << "Linear Search results:" << endl;
            cout << num << " was at index " << i << endl;
        }
    }
};

int Stack::BinarySearch(int num) {
    
    int low = 0;
    int mid = 0;
    int high = stackVect.size() - 1;
    while (high >= low) {
        mid = (high + low) / 2;
        if (stackVect.at(mid) < num) {
            low = mid + 1;
        }
        else if (stackVect.at(mid) > num) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1; //if num not found
};


void Queue::Push(int num) {
    queueVect.push_back(num);
    return;
};

int Queue::pop() {
    int firstIn = queueVect.back();
    queueVect.erase(queueVect.begin() + 0);
    return firstIn;
};

void Queue::print() {
    cout <<  "***QUEUE***" << endl;
    for (int i = queueVect.size() - 1; i > 0; i--){
        cout << queueVect.at(i) << endl;
    }
    cout << endl;
};

void Queue::LinearSearch(int num) {
    for (int i = 0; i < 100; i++){
        if(queueVect.at(i) == num) {
            cout << "Linear Search results:" << endl;
            cout << num << " was at index " << i << endl;
        }
    }
};

int Queue::BinarySearch(int num) {
    
    int low = 0;
    int mid = 0;
    int high = queueVect.size() - 1;
    while (high >= low) {
        mid = (high + low) / 2;
        if (queueVect.at(mid) < num) {
            low = mid + 1;
        }
        else if (queueVect.at(mid) > num) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1; //if num not found
};



int main() {
    Stack list;
    Queue list2;
    int numIndex;
    int numIndex1;
    int num = 12;
    vector <int> stackVect(100);
    vector <int> queueVect(100);
    ifstream inFS; //create an input file
    ifstream inFS2; //create an input file
    
    inFS.open("List1.tsv"); //opens the input file  playlist.txt
    if (!inFS.is_open()) { // checks to see if the input file opens and if it did not it lets the user knows it could not opened
        cout << "Could not open file List1.tsv" << endl;
        return 1;
    }
    
    while (!inFS.eof()){ //loops through the file until it gets to the end of the file
        for(int i = 0; i < 100; i++) {
            inFS >> stackVect[i];
            list.Push(stackVect[i]);
        }
    }
    
    inFS2.open("QueueList.tsv"); //opens the input file  playlist.txt
    if (!inFS2.is_open()) { // checks to see if the input file opens and if it did not it lets the user knows it could not opened
        cout << "Could not open file QueueList.tsv" << endl;
        return 1;
    }
    
    while (!inFS2.eof()){ //loops through the file until it gets to the end of the file
        for(int j = 0; j < 100; j++) {
            inFS2 >> queueVect[j];
            list2.Push(queueVect[j]);
        }
    }
    
    //error checking
    list.print();
    list.LinearSearch(num);
    numIndex = list.BinarySearch(num);
    if (numIndex == -1) {
        cout << num << " was not found." << endl;
    }
    else {
        cout << "Binary Search Results:" << endl;
        cout << "Found " << num << " at index " << numIndex << "." << endl << endl;
    }
    
    //exception handling
    try {
    list2.print();
    list2.LinearSearch(num);
    numIndex1 = list2.BinarySearch(num);
    if (numIndex == -1) {
        throw runtime_error("number not found");
    }
    else {
        cout << "Binary Search Results:" << endl;
        cout << "Found " << num << " at index " << numIndex1 << "." << endl << endl;
    }

    }
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl;
            cout << "that index does not exist" << endl;
        };
    
    inFS.close(); //closes the playlist.txt input file
    
    return 0;
}
