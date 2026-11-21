
#include <iostream>
using namespace std;

// Subsystem 1: TV
class TV {

public:

    void turnOn() {
        cout << "TV is turned ON" << endl;
    }

    void turnOff() {
        cout << "TV is turned OFF" << endl;
    }
};


// Subsystem 2: Sound System
class SoundSystem {

public:

    void turnOn() {
        cout << "Sound System is turned ON" << endl;
    }

    void setVolume(int volume) {
        cout << "Volume set to " << volume << endl;
    }

    void turnOff() {
        cout << "Sound System is turned OFF" << endl;
    }
};


// Subsystem 3: DVD Player
class DVDPlayer {

public:

    void turnOn() {
        cout << "DVD Player is turned ON" << endl;
    }

    void playMovie(string movie) {
        cout << "Playing movie: " << movie << endl;
    }

    void turnOff() {
        cout << "DVD Player is turned OFF" << endl;
    }
};


// Facade Class
class HomeTheatreFacade {

private:

    TV tv;
    SoundSystem sound;
    DVDPlayer dvd;

public:

    // Constructor
    HomeTheatreFacade() {}

    // Simple method to watch a movie
    void watchMovie(string movie) {

        cout << "\nStarting Home Theatre..." << endl;

        tv.turnOn();

        sound.turnOn();

        sound.setVolume(50);

        dvd.turnOn();

        dvd.playMovie(movie);

        cout << "\nMovie is ready!" << endl;
    }


    // Simple method to stop the movie
    void stopMovie() {

        cout << "\nStopping Home Theatre..." << endl;

        dvd.turnOff();

        sound.turnOff();

        tv.turnOff();

        cout << "\nHome Theatre stopped!" << endl;
    }
};


// Main Function
int main() {

    // Create Facade object
    HomeTheatreFacade homeTheatre;

    // Start movie using one simple function
    homeTheatre.watchMovie("Avengers");

    // Stop movie using one simple function
    homeTheatre.stopMovie();

    return 0;
}
