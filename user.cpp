#include <string>
#include <vector>
#include "User.h"
#include "Playlist.h"

using namespace std;

User::User(){
	this->username = "Guest";
}

User::User(string username){
	this->username = username;
}

void User::setUsername(string username){
	this->username = username;
}

string User::getUsername(){
	return this->username;
}

void User::addPlaylist(string name){
	this->playlists.push_back(Playlist(name));
}

void User::deletePlaylist(string name){
	//remove corresponding playlist from this->playlists vector
}

vector<Playlist> User::getPlaylists(){
	return this->playlists;
}

void User::setPlaylists(vector<Playlist> playlists){
	this->playlists = playlists;
}

void User::storePlaylists(){
	//create folder for user if it doesn't already exist
	//for each playlist
	//	create file
	//	for each song
	//		write: title, artist, genre, duration, likes
	//		separated by tabs (since strings may have spaces)
}

void User::loadPlaylists(){
	//if user folder does not exist, load Guest user playlists
	//for each file in user folder
	//	create playlist vector
	//		for each line in file
	//			getline delim = \t
	//			read in song parts
	//			add to playlist vector
	//	append playlist to playlists vector
	unordered_map <string, vector<string>> users_to_playlists;
	vector<string> playlist_names;
	Playlist playlist;

	users_to_playlists = Playlist::loadPlaylists();
	if (users_to_playlists.find(this->username) != users_to_playlists.end())
		playlist_names = users_to_playlists[this->username];
	else
		playlist_names = users_to_playlists["Guest"];
	
	this->playlists.clear();
	for(int i=0; i<playlist_names.size(); i++){
		playlist = Playlist(playlist_names[i]);
		playlist.loadPlaylist(this->username, playlist_names[i]);
		this->playlists.push_back(playlist);
	}

}
