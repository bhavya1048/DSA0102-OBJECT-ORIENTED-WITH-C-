
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
    int seconds;

public:
    Time(int s = 0) : seconds(s) {}

    // Prefix increment
    Time& operator++() {
        ++seconds;
        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time old = *this;
        ++seconds;
        return old;
    }

    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }

    void display() const {
        cout << seconds / 3600 << ":"
             << (seconds / 60) % 60 << ":"
             << seconds % 60 << endl;
    }
};

class Track {
public:
    string name;

    Track(string n = "") : name(n) {}
};

class Playlist {
    vector<Track> tracks;

public:
    void addTrack(string name) {
        tracks.push_back(Track(name));
    }

    Track& operator[](int index) {
        static Track invalid("Invalid Index");

        if (index < 0 || index >= (int)tracks.size()) {
            cout << "Invalid Index" << endl;
            return invalid;
        }
        return tracks[index];
    }

    const Track& operator[](int index) const {
        static const Track invalid("Invalid Index");

        if (index < 0 || index >= (int)tracks.size()) {
            cout << "Invalid Index" << endl;
            return invalid;
        }
        return tracks[index];
    }
};

int main() {
    Time t(10);

    Time a = t++;
    Time b = ++t;

    cout << "A: ";
    a.display();

    cout << "B: ";
    b.display();

    cout << "Current Time: ";
    t.display();

    cout << boolalpha;
    cout << "Equal: " << (a == b) << endl;
    cout << "Less: " << (a < b) << endl;

    Playlist p;
    p.addTrack("Song A");
    p.addTrack("Song B");

    cout << "Track: " << p[1].name << endl;
    cout << "Invalid: " << p[5].name << endl;

    return 0;
}
