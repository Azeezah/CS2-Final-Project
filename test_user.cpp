#include <iostream>
#include "song.h"
#include "playlist.h"
#include "user.h"
using namespace std;

int main(){
	User user = User("Earl");
	cout << "Loading playlist" << endl;
	user.loadPlaylists();
	cout << "Storing playlist" << endl;
	user.storePlaylists();
	return 0;
}
