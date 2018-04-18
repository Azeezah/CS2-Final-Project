#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "Song.h"

int main() 
{
  Song song;
  string songTitle;
  string songArtist;
  string songGenre;
  string songDuration;
  char quitCmd = 'a';   // Indicates quit/continue
   
  while (quitCmd != 'q') {
    try {
      song.Menu();
      }
      catch (runtime_error &excpt) {
        cout << excpt.what() << endl;
        cout << "Cannot input song playlist" << endl;
    }
    
    // Prompt user to continue/quite
    cout << endl << "Enter any key ('q' to quit): ";
    cin >> quitCmd;
  }
  
/*  cout << "Enter song info:" << endl;
  cout << "\nEnter song title:" << endl;
  getline(cin, songTitle);
  music.SetTitle(songTitle);
  
  cout << "\nEnter song artist:" << endl;
  getline(cin, songArtist);
  music.SetArtist(songArtist);
  
  cout << "\nEnter song genre:" << endl;
  getline(cin, songGenre);
  music.SetGenre(songGenre);
  
  cout << "\nEnter song duration:" << endl;
  getline(cin, songDuration);
  music.SetDuration(songDuration);
  cout << endl;
  
*/  

  return 0;  
}