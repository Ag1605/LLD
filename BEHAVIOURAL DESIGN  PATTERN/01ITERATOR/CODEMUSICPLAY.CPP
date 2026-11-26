
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ============================================
// STEP 1: ITERATOR INTERFACE
// Defines methods for traversing the playlist
// ============================================

class Iterator {
public:

    // Checks whether another song exists
    virtual bool hasNext() = 0;

    // Returns current song and moves to next
    virtual string next() = 0;

    virtual ~Iterator() {}
};


// ============================================
// STEP 2: AGGREGATE INTERFACE
// Defines how to create an iterator
// ============================================

class Playlist {
public:

    virtual Iterator* createIterator() = 0;

    virtual ~Playlist() {}
};


// ============================================
// STEP 3: CONCRETE AGGREGATE
// Stores the actual songs
// ============================================

class MusicPlaylist : public Playlist {
private:

    // Collection of songs
    vector<string> songs;

public:

    // Add a song to the playlist
    void addSong(string song) {

        songs.push_back(song);
    }

    // Give iterator access to the collection
    const vector<string>& getSongs() const {

        return songs;
    }

    // Create and return playlist iterator
    Iterator* createIterator() override;
};


// ============================================
// STEP 4: CONCRETE ITERATOR
// Implements actual traversal logic
// ============================================

class PlaylistIterator : public Iterator {
private:

    // Reference to the playlist
    const vector<string>& songs;

    // Tracks current position
    int index;

public:

    // Constructor
    PlaylistIterator(const vector<string>& playlistSongs)
        : songs(playlistSongs) {

        index = 0;
    }

    // Check whether another song exists
    bool hasNext() override {

        return index < songs.size();
    }

    // Return current song and move forward
    string next() override {

        if (hasNext()) {

            string currentSong = songs[index];

            index++;

            return currentSong;
        }

        return "";
    }
};


// Create iterator after PlaylistIterator is defined
Iterator* MusicPlaylist::createIterator() {

    return new PlaylistIterator(songs);
}


// ============================================
// STEP 5: CLIENT
// Uses iterator without knowing internal details
// ============================================

int main() {

    // Create playlist
    MusicPlaylist playlist;

    // Add songs
    playlist.addSong("Believer");
    playlist.addSong("Shape of You");
    playlist.addSong("Perfect");
    playlist.addSong("Faded");

    // Create iterator
    Iterator* iterator = playlist.createIterator();

    cout << "Music Playlist:" << endl;

    // Traverse all songs
    while (iterator->hasNext()) {

        cout << "Playing: " << iterator->next() << endl;
    }

    // Release dynamically allocated iterator
    delete iterator;

    return 0;
}
