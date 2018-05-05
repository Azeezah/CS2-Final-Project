#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include "playlist.h"
#include "song.h"

using namespace std;

Playlist::Playlist(){
   head = nullptr;
   tail = nullptr;
}

Playlist::Playlist(string titles[], int num_titles){
   head = nullptr;
   tail = nullptr;
   Song curr;
   
   for (int i=0; i<num_titles; i++){
      curr.SetTitle(titles[i]);
      this->Append(curr);
   }
};

void Playlist::Append(Song data){
   if (data.GetTitle()=="") throw runtime_error("Cannot append blank song to playlist.");
   
   NODE* node = new NODE();
   node->next = nullptr;
   node->song = data;
   if(head == nullptr){ 
      head = tail = node;
      node->next = node;    //make it circular
      node->previous = node;
   }
   else {
      tail->next = node;
      node->previous = tail;    //make it doubly linked
      tail = tail->next;    //update tail pointer
      tail->next = head;    //make it circular
      head->previous = tail;
   }
}

void Playlist::Prepend(Song song){
   if (song.GetTitle()=="") throw runtime_error("Cannot prepend blank song to playlist.");

   NODE* node = new NODE();
   node->song = song;
   node->next = head;
   head->previous = node;    //make it doubly linked
   head = node;    //update head pointer
   tail->next = head;    //make it circular
   head->previous = tail;
}

void Playlist::Remove(Song song){
   if (song.GetTitle()=="") throw runtime_error("Cannot remove blank song from playlist.");
  
   //removes the first match starting from the end
   if (tail == nullptr){ return; }    //check if list is empty
   NODE *curr = tail;
   while (curr->song.GetTitle() != song.GetTitle()){
      curr = curr->previous;    //go backward
      if (curr == tail){ return; }    //node to remove is not present in circular list
   }
   //remove curr
   if (curr == tail){ tail = curr->previous; }    //update tail pointer
   else if (curr == head){ head = curr->next; }    //update head pointer
   
   curr->previous->next = curr->next;    //link preceding node to following node
   curr->next->previous = curr->previous;    //and make it doubly linked
}

void Playlist::InsertAfter(Song old_song, Song new_song){
   if (new_song.GetTitle()=="") throw runtime_error("Cannot insert blank song in playlist.");
   
   NODE *curr = head;
   NODE *new_node = new NODE();
   new_node->song = new_song;
   
   if (head == nullptr){ return; }    //check if list is empty
   
   while (curr->song.GetTitle() != old_song.GetTitle()){
      curr = curr->next;
      if (curr == head){ return; }    //check if flight is not in circular list
   }

   if (curr == tail){ tail = new_node; }    //update tail pointer
   
   new_node->next = curr->next;    //connect following node
   new_node->next->previous = new_node;    //make it doubly linked

   curr->next = new_node;    //connect the preceding node
   curr->next->previous = curr;    //make it doubly linked
}

void Playlist::Print(){
   if(head==nullptr){ return; }    //check if empty
   NODE *curr = head;
   do {
      cout << curr->song.GetTitle() << endl;
      curr = curr->next;
   } while (curr != head);
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
