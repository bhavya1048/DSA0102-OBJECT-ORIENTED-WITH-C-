#include <iostream>
using namespace std;

class Cart {
public:
    double total;

    Cart(double t) : total(t) {}
};

int main() {
    Cart a(500), b(800), c(650);

    Cart* carts[] = {&a, &b, &c};

    Cart* highest = carts[0];

    for (int i = 1; i < 3; i++) {
        if (carts[i]->total > highest->total) {
            highest = carts[i];
        }
    }

    cout << "Highest Cart Total: " << highest->total;

    return 0;
}