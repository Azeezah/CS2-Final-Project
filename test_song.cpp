#include <iostream>
#include "song.h"

using namespace std;

int main(){
  Song song = Song("Beat it", "Micheal Jackson", 4.3, "Pop", 20);
  song.play("Peace");
  cout << endl;
  Song song2 = Song("Thriller", "Micheal Jackson", 4.3, "Pop", 30);
  song2.play("Travis");
  cout << endl;
  cout << "(song > song2) = " << (song > song2) << endl;
  cout << "(song < song2) = " << (song < song2) << endl;
}
