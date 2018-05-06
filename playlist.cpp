#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include "playlist.h"
#include "song.h"

using namespace std;

Playlist::Playlist(){
	this->name = "unnamed playlist";
}
      
void Playlist::print(){
   cout << this->name << endl;
   for(int i=0; i<this->songs.size(); i++){
      cout << " | " << songs[i].GetTitle() << endl;
   }
}


Playlist::Playlist(string name){
   this->name = name;
}

string Playlist::getName(){
   return this->name;
}

void Playlist::play(){
   //for song in playlist:
   //	print song info, and show nice graphics
}

void Playlist::removeSong(Song song){
   //remove song from playlist
}

void Playlist::addSong(Song song){
   this->songs.push_back(song);
}

unordered_map <string, vector<string>> Playlist::loadPlaylists(){
	//returns a map username -> list of playlist names
	unordered_map <string, vector<string>> lists;

	//this reads the playlist names from a file
	//hopefully this is a little more portable 
	//than listing them from the user folders directly
	ifstream f;
	f.open("user_playlists.txt");
	if(!f.is_open()){ cout << "couldn't open file" << endl; return lists; }
	
	vector<string> playlist_names;
	string token;
	while(getline(f, token, '\t')){
		if (token.back() == '\n') {
			//cout << "name: " << token.substr(1) << endl;
			lists[token.substr(0, token.size()-1)] = playlist_names;
			playlist_names.clear();
		} else {
			playlist_names.push_back(token);
			//cout << " | " << token << endl;
		}
	}
	return lists;
}

void Playlist::loadPlaylist(string user, string playlist_name){
	this->songs.clear();
	
	string title, artist, genre;
	double duration;
	int likes;
	ifstream f;	
	f.open("users/"+user+"/playlists/"+playlist_name);
	//TODO: if !f.is_open() try using backslashes
	if(!f.is_open()){ cout << "couldn't open playlist file: " << ("users/"+user+"/playlists/"+playlist_name) << endl; return; }
	while(!f.eof()){
		getline(f, title, '\t');
		getline(f, artist, '\t');
		f >> duration;
		f.ignore();   //remove following \t from the buffer
		getline(f, genre, '\t');
		f >> likes;
		f.ignore();   //remove following \t from the buffer
		if (!f.good()) break;
		cout << "Title: " << title \
			<< " Artist: " << artist \
			<< " Duration: " << duration \
			<< " Genre: " << genre \
			<< " Likes: " << likes << endl;
		this->songs.push_back(Song(title, artist, duration, genre, likes));
	}
}
