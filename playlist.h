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
  void print();
  string getName();
  void play();
  void removeSong(Song song);
  void addSong(Song song);
  vector<Song> songs;  //should really be private
  static unordered_map <string, vector<string>> loadPlaylists();
  void loadPlaylist(string user, string playlist_name);
  private:
  string name;
};

#endif
