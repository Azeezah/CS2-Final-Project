#include <iostream>
#include <string>
#include <unordered_map>
#include "playlist.h"

using namespace std;

int main(){
  Playlist playlist;
  Song song;
  
  try {
    playlist.Append(song);
  }
  catch (runtime_error& excpt) {
    cout << excpt.what() << endl;
  }

  playlist.loadPlaylist("Mike", "I got an A");
  unordered_map map = Playlist::loadPlaylists();

  return 0;
}
