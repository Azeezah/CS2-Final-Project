#include <iostream>
#include "song.h"

using namespace std;

int main(){
  Song song = Song("Beat it", "Micheal Jackson", 4.3, "Pop", 20);
  song.play("Peace");
}
