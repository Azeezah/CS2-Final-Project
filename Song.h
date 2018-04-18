#ifndef SONGS_H
#define SONGS_H

class Songs {
public:
  Song();
  void SetTitle(string songName);  
  void SetArtist(string artistName); 
  void SetGenre(string songGenre);
  void SetDuration(double songDuration);
  string Display() const;

  string getTitle() const;
  string getArtist() const;
  string getGenre() const;
  double getDuration() const;
    
  //void Addsong(int counter); 
  //void Remove(int counter); 
  //void Exit(); 
  int Menu();
    
private:
   string title;
   string artist;
   double duration; 
   string genre;
};
 
#endif 
