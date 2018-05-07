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

void Playlist::loadPlaylist(string user, string playlist_name){
	this->songs.clear();
	
	string title, artist, genre;
	double duration;
	int likes;
	ifstream f;	
	f.open("playlists/"+user+"_"+playlist_name);
	
	if(!f.is_open()){ cout << "couldn't open playlist file: " << ("playlists/"+user+"_"+playlist_name) << endl; return; }
	while(!f.eof()){
		getline(f, title, '\t');
		getline(f, artist, '\t');
		f >> duration;
		f.ignore();   //remove following \t from the buffer
		getline(f, genre, '\t');
		f >> likes;
		f.ignore();   //remove following \t from the buffer
		if (!f.good()) break;
		//cout << "Title: " << title \
			<< " Artist: " << artist \
			<< " Duration: " << duration \
			<< " Genre: " << genre \
			<< " Likes: " << likes << endl;
		this->songs.push_back(Song(title, artist, duration, genre, likes));
	}
}


void Playlist::storePlaylist(string user){
	ofstream f;
	f.open("playlists/"+user+"_"+this->name);
	for (int i=0; i<this->songs.size(); i++){
		f << this->songs[i].GetTitle() << '\t' \
		<< this->songs[i].GetArtist() << '\t' \
		<< this->songs[i].GetDuration() << '\t' \
		<< this->songs[i].GetGenre() << '\t' \
		<< this->songs[i].GetLikes() << endl;
	}
}
