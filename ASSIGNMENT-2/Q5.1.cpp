#include <iostream>
#include <string>
using namespace std;

class BusTicket {
private:
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    string name;

public:
    BusTicket(string n) {
        name = n;
        seat = 0;

        if (issued < CAPACITY) {
            issued++;
            seat = issued;
        }
    }

    static int count() {
        return issued;
    }

    void print() const {
        cout << name << ": ";

        if (seat != 0)
            cout << "Seat " << seat;
        else
            cout << "Waiting";

        cout << '\n';
    }
};

int BusTicket::issued = 0;

int main() {
    string names[4];

    cout << "Enter names of 4 students:\n";
    for (int i = 0; i < 4; i++)
        cin >> names[i];

    BusTicket trip[4] = {
        BusTicket(names[0]),
        BusTicket(names[1]),
        BusTicket(names[2]),
        BusTicket(names[3])
    };

    cout << "Ticket details:\n";
    for (const BusTicket& t : trip)
        t.print();

    cout << "Issued: " << BusTicket::count() << '\n';

    return 0;
}