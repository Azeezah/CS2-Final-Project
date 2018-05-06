#include <iostream>
#include <string>
#include <unordered_map>
#include "playlist.h"

using namespace std;

int main(){
  Playlist playlist;
  Song song = Song("Beat it", "Micheal Jackson", 4.3, "Pop", 20);
  playlist.addSong(song);
  song = Song("Thriller", "Micheal Jackson", 4.9, "Pop", 2);
  playlist.addSong(song);
  playlist.print();
  playlist.loadPlaylist("Mike", "I got an A");
  unordered_map<string, vector<string>> map = Playlist::loadPlaylists();

  return 0;
}
