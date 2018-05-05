#include <iostream>
#include "song.h"
#include "playlist.h"
#include "user.h"
using namespace std;

int main(){
	User user = User("Mike");
	user.loadPlaylists();
	return 0;
}
