#include <iostream>
using namespace std;

class Bill {
public:
    virtual double total() const {
        return 0;
    }
};

class OPBill : public Bill {
public:
    double total() const override {
        return 500;
    }
};

int main() {
    Bill* b = new OPBill();

    cout << b->total();

    delete b;
}