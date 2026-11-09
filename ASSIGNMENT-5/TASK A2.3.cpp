#include <iostream>
using namespace std;

class Bill {
public:
    virtual ~Bill() {
        cout << "~Bill ";
    }
};

class OPBill : public Bill {
public:
    ~OPBill() override {
        cout << "~OPBill ";
    }
};

int main() {
    Bill* b = new OPBill();
    delete b;
}