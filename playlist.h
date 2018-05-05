#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include <vector>
#include <unordered_map>
#include "song.h"

using namespace std;

class Playlist {
  public:
  Playlist();
  Playlist(string name_of_playlist);
  Playlist(string songs[], int num_songs);
  void Append(Song data);
  void Prepend(Song data);
  void Remove(Song data);
  void InsertAfter(Song new_value, Song old_value);
  void Print();

  string getName();
  void play();
  void removeSong(Song song);
  void addSong(Song song);
  vector<Song> songs;  //should really be private
  static unordered_map <string, vector<string>> loadPlaylists();
  void loadPlaylist(string user, string playlist_name);
  private:
  string name;

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
