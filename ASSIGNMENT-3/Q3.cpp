#include <iostream>
using namespace std;

class Event {
    int rows, seats;
    bool** map;

public:
    Event(int r, int s) : rows(r), seats(s) {
        map = nullptr;

        if (rows > 0 && seats > 0) {
            map = new bool*[rows];

            for (int i = 0; i < rows; i++)
                map[i] = new bool[seats]{};
        }

        cout << "Event Created" << endl;
    }

    void book(int r, int s) {
        if (map && r >= 0 && r < rows &&
            s >= 0 && s < seats && !map[r][s]) {
            map[r][s] = true;
            cout << "Seat Booked" << endl;
        }
        else {
            cout << "Booking Failed" << endl;
        }
    }

    void cancel(int r, int s) {
        if (map && r >= 0 && r < rows &&
            s >= 0 && s < seats && map[r][s]) {
            map[r][s] = false;
            cout << "Booking Cancelled" << endl;
        }
        else {
            cout << "Cancellation Failed" << endl;
        }
    }

    ~Event() {
        if (map != nullptr) {
            for (int i = 0; i < rows; i++)
                delete[] map[i];

            delete[] map;
        }

        cout << "Event Closed" << endl;
    }
};

int main() {
    Event e1(2, 3);

    e1.book(0, 1);
    e1.cancel(0, 1);

    {
        Event e2(2, 2);
        e2.book(1, 1);
    }

    Event* e3 = new Event(3, 3);
    e3->book(0, 0);
    delete e3;

    return 0;
}