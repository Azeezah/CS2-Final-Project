#include <iostream>
#include <string>
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
  
  return 0;
}