#ifndef USER_H
#define USER_H

#include <string>
#include "playlist.h"

using namespace std;

class User {
public:
	User();
	User(string username);
	void setUsername(string username);
	string getUsername();

	void loadPlaylists();
	void storePlaylists();
	void addPlaylist(string name);
	void deletePlaylist(string name);
	vector<Playlist> getPlaylists();
	void setPlaylists(vector<Playlist> playlists);
private:
	string username;
	vector<Playlist> playlists;
};

#endif
