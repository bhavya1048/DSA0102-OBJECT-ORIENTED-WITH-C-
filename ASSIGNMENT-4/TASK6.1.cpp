#include <iostream>
using namespace std;

class Vehicle {
    int type;
    double rate;

public:
    Vehicle(int t, double r) : type(t), rate(r) {}

    double rentalCharge(int days) {
        switch (type) {
            case 1: return rate * days + 100;
            case 2: return rate * days + 150;
            case 3: return rate * days + 200;
            case 4: return rate * days + 500;
            default: return 0;
        }
    }
};

int main() {
    Vehicle v(1, 100);

    cout << "Rental Charge: " << v.rentalCharge(2);

    return 0;
}