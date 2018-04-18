#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include "song.h"

using namespace std;

class Playlist {
  public:
  Playlist();
  Playlist(string songs[], int num_songs);
  void Append(Song data);
  void Prepend(Song data);
  void Remove(Song data);
  void InsertAfter(Song new_value, Song old_value);
  void Print();
  
  private:

  //defining this here to keep everything encapsulated
  //and since it's only used internally
  struct NODE {    
   Song song;
   NODE *next;
   NODE *previous;
  };
   
  NODE *head, *tail;
};

#endif