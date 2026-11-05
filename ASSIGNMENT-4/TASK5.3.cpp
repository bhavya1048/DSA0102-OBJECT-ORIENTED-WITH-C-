#include <iostream>
#include <vector>
using namespace std;

class Cart {
public:
    double total;

    Cart(double t) : total(t) {}
};

int main() {
    vector<Cart> carts;

    carts.push_back(Cart(500));
    carts.push_back(Cart(800));
    carts.push_back(Cart(650));

    double highest = carts[0].total;

    for (int i = 1; i < carts.size(); i++) {
        if (carts[i].total > highest) {
            highest = carts[i].total;
        }
    }

    cout << "Highest Total: " << highest;

    return 0;
}