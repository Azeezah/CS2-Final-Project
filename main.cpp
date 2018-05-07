#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  //rand, srand
#include <ctime>
#include "song.h"
#include "playlist.h"
#include "user.h"

using namespace std;

/* Local Dependencies:
 * User::User(string username);
 * void User::loadPlaylists();
 * void User::addPlaylist(string);
 * vector<Playlists> User::getPlaylists();
 * string Playlist::getName();
 * void User::deletePlaylist();
 * void Playlist::play();
 * vector<Song> Playlist::songs;
 * void Playlist::removeSong();
 * void Song::play();
 * void Playlist::addSong(Song song);
 * Song::Song(string title, string artist, double duration, string genre, int likes);
 * void User::setPlaylists(vector<Playlist> playlists);
 * void User::storePlaylists();
 */

void new_playlist_dialogue(User& user);
void select_playlist_dialogue(User& user);
void playlist_menu_dialogue(User& user, Playlist& playlist);
void select_song_dialogue(User& user, Playlist& playlist);
void song_menu_dialogue(User& user, Playlist& playlist, Song& song);
void new_song_dialogue(Playlist& playlist);

int main(){
	srand(time(0));  //seed random to use later

	//removed workaround now that playlist loading is fixed
	//user.loadPlaylist() works as intended, and will load the Guest playlists if user is new
	string username;
	cout << "Username: ";
	cin >> username;
	User user = User(username);
	user.loadPlaylists();
	//main menu
	//	add new playlist
	//	select playlist
	//	quit
	bool done = false;
	while (!done){
		//To-Do: Add new option of viewing default playlist below
		cout << "Enter a selection 1-3\n \
			\t 1. Create new playlist\n \
			\t 2. Select playlist\n \
			\t 3. Quit" << endl;
		int selection;
		cin >> selection;
		switch(selection){
			case 1: new_playlist_dialogue(user);
				done = true;
				break;
			case 2: select_playlist_dialogue(user);
				done = true;
				break;
			case 3: done = true;
				break;
			default: cout << "Sorry I didn't get that.  Come again?" << endl;
				 break;
		}
	}
	cout << "Good day" << endl;
	user.storePlaylists(); 
	return 0;
}

void new_playlist_dialogue(User& user){
	cout << "Name of playlist: ";
	string name_of_playlist;
	cin >> name_of_playlist;
	user.addPlaylist(name_of_playlist);
}

void select_playlist_dialogue(User& user){
	vector<Playlist> playlists = user.getPlaylists();
	if (playlists.empty()) {
		cout << "You have no playlists" << endl;
		return;
	}
	
	cout << "Enter a selection 1-" << playlists.size() << endl;
	for (int i=0; i < playlists.size(); i++){
		cout << i+1 << ". " << playlists[i].getName() << endl;
	}
	int selection;
	cin >> selection;
	if (selection >= playlists.size() || selection < 1) {
		cout << "That selection is out of range." << endl;
		return;
	}
	playlist_menu_dialogue(user, playlists[selection-1]);
	user.setPlaylists(playlists);    //it'd be faster to just reference playlist from user
}

void playlist_menu_dialogue(User& user, Playlist& playlist){
	//playlist menu
	//	delete playlist
	//	play playlist
	//	add new song
	//	select song
	//	back
	cout << "You've selected " << playlist.getName() << endl;
	cout << "Enter a selection 1-5\n \
		\t 1. Delete playlist\n \
		\t 2. Play playlist\n \
		\t 3. Add new song\n \
		\t 4. Select song\n \
		\t 5. Go back" << endl;
	int selection;
	cin >> selection;
	switch(selection){
		case 1: user.deletePlaylist(playlist.getName());
			break;
		case 2: playlist.play();
			break;
		case 3: new_song_dialogue(playlist);
			break;
		case 4: select_song_dialogue(user, playlist);
			break;
		case 5: //done = true;  //it'll return anyway
			break;
		default: cout << "Sorry I don't understand." << endl;  //or throw error
			 break;
	}
}

void select_song_dialogue(User& user, Playlist& playlist){
	if (playlist.songs.empty()) {
		cout << "This playlist is empty." << endl;
		return;
	}
	cout << "Enter a selection 1-" << playlist.songs.size() << endl;
	for (int i=0; i < playlist.songs.size(); i++){
		cout << i+1 << ". " << playlist.songs[i].GetTitle() << endl;
	}
	int selection;
	cin >> selection;
	if (selection >= playlist.songs.size() || selection < 1) {
		cout << "That selection is out of range." << endl;
		return;
	}
	song_menu_dialogue(user, playlist, playlist.songs[selection-1]);
}

void song_menu_dialogue(User& user, Playlist& playlist, Song& song){
	//song menu
	//	remove song from playlist
	//	play song
	//	back
	cout << "Enter a selection 1-3\n \
		\t 1. Remove song from playlist\n \
		\t 2. Play song\n \
		\t 3. Go back" << endl;
	int selection;
	cin >> selection;
	switch(selection){
		case 1: playlist.removeSong(song);
			break;
		case 2: song.play(user.getUsername());  //shows song info and fancy graphics for song duration
			break;
		case 3: //done = true;   //it returns anyway
			break;
		default: cout << "Sorry I don't understand." << endl;  //or throw error
			 break;
	}
}

void new_song_dialogue(Playlist& playlist){
	//new song form
	//	title
	//	artist
	//	duration
	//	genre

	//TODO: get spaces in input without breaking cin
	string title, artist, genre;
	double duration;
	int likes;
	cout << "New Song: " << endl;
	cout << "\tTitle: ";
	cin >> title;
	cout << "\tArtist: ";
	cin >> artist;
	cout << "\tDuration: ";
	cin >> duration;
	cout << "\tGenre: ";
	cin >> genre;
	likes = rand() % 100;
	playlist.addSong(Song(title, artist, duration, genre, likes));
}	
