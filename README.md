# CS2-Final-Project: Sounds

Presenting Sounds: A new way to enjoy the music you love.

For the use case of playing M playlists:
This application has a runtime complexity of O(MNlogN), where N is the average number of songs in the playlist.  For each playlist, first, the application sorts it, which takes O(NlogN) time.  Then it plays is, which takes O(N) time.

Files:
- main.cpp
- users.h
- users.cpp
- playlist.h
- playlist.cpp
- song.h
- song.cpp
- sort.h
- sort.cpp

Compile:
$ g++ main.cpp users.cpp playlist.cpp song.cpp sort.cpp -o sounds.exe

Run:
$ sounds

Compile Tests:
$ g++ test\_users.cpp users.cpp -o test.exe

$ g++ test\_search.cpp search.cpp -o test.exe

$ g++ test\_playlist.cpp playlist.cpp song.cpp -o test.exe

$ g++ test\_sort.cpp sort.cpp -o test.exe

$ g++ test\_song.cpp song.cpp -o test.exe

Run Test:

$ test
