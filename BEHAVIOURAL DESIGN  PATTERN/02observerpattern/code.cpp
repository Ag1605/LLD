
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Observer interface
// Every subscriber must implement the update() function.
class Observer {
public:
    virtual void update(string videoName) = 0;

    virtual ~Observer() {}
};

// Subject interface
// The subject manages subscribers.
class Subject {
public:
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* observer) = 0;
    virtual void notifyObservers(string videoName) = 0;

    virtual ~Subject() {}
};

// Concrete Subject
// Represents a YouTube channel.
class YouTubeChannel : public Subject {
private:
    string channelName;

    // Stores all subscribed observers.
    vector<Observer*> subscribers;

public:
    YouTubeChannel(string name) {
        channelName = name;
    }

    // Subscribe a user to the channel.
    void subscribe(Observer* observer) override {
        subscribers.push_back(observer);

        cout << "Subscriber added to "
             << channelName << endl;
    }

    // Remove a subscriber from the channel.
    void unsubscribe(Observer* observer) override {
        for (int i = 0; i < subscribers.size(); i++) {

            if (subscribers[i] == observer) {
                subscribers.erase(subscribers.begin() + i);

                cout << "Subscriber removed from "
                     << channelName << endl;

                return;
            }
        }
    }

    // Notify every subscriber when a new video is uploaded.
    void notifyObservers(string videoName) override {
        for (int i = 0; i < subscribers.size(); i++) {
            subscribers[i]->update(videoName);
        }
    }

    // Upload a new video.
    void uploadVideo(string videoName) {
        cout << "\n" << channelName
             << " uploaded: " << videoName << endl;

        notifyObservers(videoName);
    }
};

// Concrete Observer
// Represents a YouTube subscriber.
class Subscriber : public Observer {
private:
    string subscriberName;

public:
    Subscriber(string name) {
        subscriberName = name;
    }

    // Called automatically when the channel uploads a video.
    void update(string videoName) override {
        cout << subscriberName
             << " received notification: "
             << videoName << endl;
    }
};

int main() {

    // Create a YouTube channel.
    YouTubeChannel channel("CodeWithMe");

    // Create subscribers.
    Subscriber user1("Akshat");
    Subscriber user2("Rahul");
    Subscriber user3("Aman");

    // Subscribe users to the channel.
    channel.subscribe(&user1);
    channel.subscribe(&user2);
    channel.subscribe(&user3);

    // Upload first video.
    channel.uploadVideo("Observer Pattern in C++");

    // Rahul unsubscribes.
    channel.unsubscribe(&user2);

    // Upload second video.
    channel.uploadVideo("Factory Pattern in C++");

    return 0;
}
