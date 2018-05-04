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
}
