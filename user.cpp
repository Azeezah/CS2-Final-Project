#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "user.h"
#include "playlist.h"

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
	//for each playlist
	//	create file
	//	for each song
	//		write: title, artist, genre, duration, likes
	//		separated by tabs (since strings may have spaces)
	ofstream f;
	f.open("playlists/"+this->username+"_playlist_names");
	for(int i=0; i<this->playlists.size(); i++){
		f << this->playlists[i].getName() << endl;
	}    //this loop is separate so we can close the file quickly
	f.close();
	for(int i=0; i<this->playlists.size(); i++){
		this->playlists[i].storePlaylist(this->username);
	}
}

void User::loadPlaylists(){
	//if user folder does not exist, load Guest user playlists
	//for each of user's playlists
	//	create playlist vector
	//		for each line in file
	//			getline delim = \t
	//			read in song parts
	//			add to playlist vector
	//	append playlist to playlists vector
	
	Playlist playlist;
	string playlist_name;
	string user = this->username;
	vector<string> playlist_names;
	ifstream f;

	f.open("playlists/"+user+"_playlist_names");
	if (!f.is_open()){ 
		user = "Guest";
	        f.open("playlists/"+user+"_playlist_names");
	}
	cout << "Loading playlists/"+user+"_playlist_names" << endl;

	while(!f.eof()){
		getline(f, playlist_name);
		if (!f.good()) break;
		playlist_names.push_back(playlist_name);
	}
	//cout << "playlist_names.size(): " << playlist_names.size() << endl;
	this->playlists.clear();
	for(int i=0; i<playlist_names.size(); i++){
		playlist = Playlist(playlist_names[i]);
		playlist.loadPlaylist(user, playlist_names[i]);
		this->playlists.push_back(playlist);
	}
	//cout << "this->playlists.size(): " << this->playlists.size() << endl;
}
