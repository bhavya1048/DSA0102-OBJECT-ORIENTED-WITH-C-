#include <iostream>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual string type() const = 0;
    virtual ~Bill() = default;
};

class OutPatientBill : public Bill {
public:
    double total() const override {
        return 500 + 1200;
    }

    string type() const override {
        return "Outpatient";
    }
};

class InPatientBill : public Bill {
public:
    double total() const override {
        return 3 * 2500 + 40000;
    }

    string type() const override {
        return "Inpatient";
    }
};

class DayCareBill : public Bill {
public:
    double total() const override {
        return 18000;
    }

    string type() const override {
        return "Daycare";
    }
};

class EmergencyBill : public Bill {
public:
    double total() const override {
        return 5000 + 1200 * 3;
    }

    string type() const override {
        return "Emergency";
    }
};

int main() {
    OutPatientBill op;
    InPatientBill ip;
    DayCareBill dc;
    EmergencyBill em;

    Bill* bills[] = {&op, &ip, &dc, &em};

    for (Bill* b : bills) {
        cout << b->type() << ": "
             << b->total() << endl;
    }
}