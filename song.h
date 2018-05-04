#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
using namespace std;

class Song { //create the song class
    //create public variables
public:
    Song();
    Song(string title, string artist, double duration, string genre, int likes);
    void play();

    //mutators
    void SetArtist(string songArtist);
    void SetTitle(string songTitle);
    void SetDuration(double songDuration);
    void SetGenre(string songGenre);
    
    //accessors
    string GetArtist() const;
    string GetTitle() const;
    double GetDuration() const;
    string GetGenre() const;
    
    //creats private variables
private:
    string artist;
    string title;
    double duration;
    string genre;
    int likes;
    
};

struct NODE {
    NODE *next;
    NODE *previous;
};

class DoublyList { //create a doublyList class
private:
    NODE *head; //Use the data type node to initialize head, tail, curNode, sucNode and predNode
    NODE *tail;
    NODE *curNode;
    NODE *sucNode;
    NODE *predNode;
    
public:
    DoublyList() {
        head = NULL; //set head, tail, curNode, sucNode and predNode to empty
        tail = NULL;
        curNode = NULL;
        sucNode = NULL;
        predNode = NULL;
        
    }
    //DoublyList();
    void prepend(NODE *newNode); //initialize the prepend function
    void append(NODE *newNode);  //initialize the append function
    void remove(NODE *currNode);   //initialize the remove function
    void insertAfter(NODE *curNode, NODE *newNode);
    void print();
    
};

class stack{
    NODE *head;
public:
    stack() // constructor
    {
        head = NULL;
    }
    void push(NODE *newNode); // to insert an element
    void pop();  // to delete an element
};


#endif /* SONG_H */
