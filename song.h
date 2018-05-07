#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;

class Song { //create the song class
    //create public variables
public:
    Song();
    Song(string title, string artist, double duration, string genre, int likes);
    void play(string username);

    //mutators
    void SetArtist(string songArtist);
    void SetTitle(string songTitle);
    void SetDuration(double songDuration);
    void SetGenre(string songGenre);
    void SetLikes(int songLikes);

    //accessors
    string GetArtist() const;
    string GetTitle() const;
    double GetDuration() const;
    string GetGenre() const;
    int GetLikes() const;

    //friend functions can access private variables without actually being part of the class
    //we'll overload the comparison operators so we can easily compare songs by likes
    friend bool operator> (const Song& song1, const Song& song2);
    friend bool operator<= (const Song& song1, const Song& song2);
    friend bool operator< (const Song& song1, const Song& song2);
    friend bool operator>= (const Song& song1, const Song& song2);

    //creates private variables
private:
    string artist;
    string title;
    double duration;
    string genre;
    int likes;  
};

#endif /* SONG_H */
