//
//  DoublyList.cpp
//  HW2
//
//  Created by Samantha-Jo Cunningham on 2/27/18.
//  HUid: @02787273
//  Copyright © 2018 Samantha-Jo Cunningham. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

#include "song.h" //include the header file

using namespace std;

Song::Song(){}

Song::Song(string title, string artist, double duration, string genre, int likes){
    this->title = title;
    this->artist = artist;
    this->genre = genre;
    this->duration = duration;
    this->likes = likes;
}

void Song::play(){
    cout << "Now playing " << title << " by " << artist << "... " << endl;
    cout << "Genre " << genre << "Duration: " << duration << "Likes: " << likes << endl; 
}

void DoublyList::prepend(NODE *newNode) { //prepend function that adds a new node to the head of the list
    if (head == NULL) { //checks to see if the list is Null
        head = newNode; //prepends the head and tail with the newnode
        tail = newNode;
    }
    else {
        newNode->next = head; //prepends newnode to the head of the list
        head->previous = newNode;
        head = newNode; //sets the head to newnode
    }
}

void DoublyList::append(NODE *newNode) { //append function that adds a new node to the tail of the list
    if (head == NULL) { //checks to see if the list is Null
        head = newNode; //appends the head and tail with the newnode
        tail = head;
        
    }
    else {
        tail->next = newNode; //adds the newnode to the tail of the list
        newNode->previous = tail;
        tail = newNode; //sets the newnode as the tail
        tail->next = head; //sets the tail next to head to create a circular list
    }
}

void DoublyList::remove(NODE *currNode){ //this function removes a node from the list
    
    sucNode = currNode->next; //sets successor node to current node next
    predNode = currNode->previous; //sets predecessor node to current node previous
    
    if (sucNode != NULL) { //checks to see if sucnode is null
        sucNode->previous = predNode; // if its not null remove currnode
        
    }
    
    if (predNode != NULL) { //checks to see if prednode is null
        predNode->next = sucNode; // if its not null remove currnode
        return;
        
    }
    
    if (head == currNode) { // Removes head
        head = sucNode;
    }
    
    if (currNode == tail) { // Removes tail
        tail = predNode;
    }
}

void DoublyList::insertAfter(NODE *curNode, NODE *newNode){ //This function inserts after a given node
    
    if (head == NULL) { //checks to see if the list is Null
        head = newNode; ////inserts the newnode at the head and tail
        tail = newNode;
    }
    else if (curNode == tail) { //inserts newnode at the tail
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        newNode->next = head;
        
    }
    else { //inserts newnode after curnode
        sucNode = curNode->next;
        newNode->next = sucNode;
        newNode->previous = curNode;
        curNode->next = newNode;
        sucNode->previous = newNode;
    }
    
}



/*void DoublyList::print(){ //prints the list
    NODE *curNode;
    curNode = head; //set curNode to the head of the list
    int i = 1;
    cout << "Flight Records for HowardAir Flight CSCI0136:";
    do { //prints the list until curNode = head again
        cout << endl;
        cout << i << ". " << curNode->flight.destination << " to " << curNode->next->flight.destination;
        curNode = curNode->next;
        i++;
    }
    while (curNode != head); //creates a circular list
    
    
} */

void Song::SetTitle(string songTitle) {
    title = songTitle;
    return;
    
}

void Song::SetDuration(double songDuration) {
    duration = songDuration;
    return;
}

void Song::SetGenre(string songGenre) {
    genre = songGenre;
    return;
}

string Song::GetArtist() const {
    return artist;
}

string Song::GetTitle() const {
    return title;
}

double Song::GetDuration() const {
    return duration;
}

string Song::GetGenre() const {
    return genre;
}

