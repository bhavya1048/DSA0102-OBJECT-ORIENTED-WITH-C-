#include <iostream>
#include <string>
using namespace std;

class Cart {
    string item;
    double price;

public:
    Cart& setItem(string item, double price) {
        this->item = item;
        this->price = price;
        return *this;
    }

    void display() {
        cout << item << " : " << price << endl;
    }
};

int main() {
    // 1. Direct object
    Cart c;
    c.setItem("Rice", 60);
    c.display();

    // 2. Pointer to object
    Cart* p = &c;
    p->display();

    // 3. Reference to object
    Cart& r = c;
    r.display();

    // 4. Dynamic object
    Cart* d = new Cart;
    d->setItem("Oil", 180);
    d->display();

    delete d;

    return 0;
}