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
    
    //accessors
    string GetArtist() const;
    string GetTitle() const;
    double GetDuration() const;
    string GetGenre() const;
    
    //creats private variables
private:
    string artist;
    string title;
    double duration;
    string genre;
    int likes;
    
};

#endif /* SONG_H */
