#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Song.h"

Song::Song() //default constructor
{

name = ""; 
art = "";
alb = "";

}

//Song function to get song title
string Song::getTitle() const {
  return title;
}

void Song::SetTitle(string songName) {
  name = student;
}

double Song::getDuration() const {
  return duration;
} 

void Song::SetDuration(double songDuration) {
  duration = songDuration;
  if (duration < 0) {   //Error checking, non-negative duration
      throw runtime_error("Invalid duration");
   }
}

string Song::getArtist() const {
  return artist;
}

string Song::SetArtist(string artistName) {
  artist = artistName;
}

string Song::getGenre() const {
  return genre;
} 

string Song::SetGenre(string songGenre) {
  genre = songGenre;
} 

/*void Song::Addsong (int counter) {
  
}*/

void Song::Display() const{
  cout << "\nHere are the songs in your playlist" << endl;
  cout << "Title: " << SongTitle() << endl;
  cout << "Artist: " << SetArtist() << endl;
  cout << "Duration: " << SetDuration() << endl;
  cout << "Genre: " << SetGenre() << endl;
  
  Menu();
}

/*void Song::Exit (int counter) {
  
}*/

int Song::Menu() {
  //Display Menu
  cout << "Pick a choice from the list:" << endl;
  cout << "1. Add a song" << endl;
  cout << "2. Remove a song" << endl;
  cout << "3. Display all the songs in the list" << endl;
  cout << "4. Quit" << endl;

  cin >> option; // Getting input 

  switch (option) {
  case 1:
  cout << "\nAdd a song" << endl;
  void AddSong (int counter); 
  counter++; 
  break;
  case 2:
  cout << "\nRemove a song" << endl;
  void Remove(); 
  break;
  case 3:
  cout << "\nDisplay a song" << endl; 
  void Display(); 
  break;
  case 4: 
  cout<< "\nQuit" << endl; 
  void Exit(); 
  break;
  default:
  cout << "\nInput a value between 1-4" << endl;
  return Menu();
  }
}