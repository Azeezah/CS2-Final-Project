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

#include "song.h" //include the song header file

using namespace std;

Song::Song(){}  //empty default constructor

Song::Song(string title, string artist, double duration, string genre, int likes){
    this->title = title;
    this->artist = artist;
    this->genre = genre;
    this->duration = duration;
    this->likes = likes;
}

void Song::play(string username) {
    cout << username << " is now listening to " << title << " by " << artist << endl;
    cout << "Genre: " << genre << endl \
	 << "Duration: " << duration << endl \
	 << "Likes: " << likes << endl;
}

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

void Song::SetLikes(int songLikes) {
    likes = songLikes;
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

int Song::GetLikes() const {
    return likes;
}

//we don't need the scoping operator here since these are friend functions
//friend functions can access private variables without actually being part of the class
bool operator> (const Song& song1, const Song& song2){
    return song1.likes > song2.likes;
}
bool operator<= (const Song& song1, const Song& song2){
    return song1.likes <= song2.likes;
}
bool operator< (const Song& song1, const Song& song2){
    return song1.likes < song2.likes;
}
bool operator>= (const Song& song1, const Song& song2){
    return song1.likes >= song2.likes;
}



