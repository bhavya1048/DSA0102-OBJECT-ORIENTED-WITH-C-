#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;

class Bill {
protected:
    string patient;

public:
    Bill(string p) : patient(p) {}

    virtual ~Bill() = default;

    virtual double total() const = 0;
    virtual string type() const = 0;
};

class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(string p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OP";
    }
};

class InPatient : public Bill {
    int days;
    double rate, procedure;

public:
    InPatient(string p, int d, double r, double s)
        : Bill(p), days(d), rate(r), procedure(s) {}

    double total() const override {
        return days * rate + procedure;
    }

    string type() const override {
        return "IP";
    }
};

// New bill type
class RehabilitationBill : public Bill {
    int sessions;
    double perSession;

public:
    RehabilitationBill(string p, int n, double rate)
        : Bill(p), sessions(n), perSession(rate) {}

    double total() const override {
        return sessions * perSession;
    }

    string type() const override {
        return "REHAB";
    }
};

class Payer {
public:
    virtual ~Payer() = default;

    virtual double covered(double amount) const = 0;
    virtual string name() const = 0;
};

class Insurance : public Payer {
    double limit, copay;

public:
    Insurance(double l, double c)
        : limit(l), copay(c) {}

    double covered(double amount) const override {
        return min(amount, limit)
               * (1 - copay / 100);
    }

    string name() const override {
        return "Insurance";
    }
};

// New payer
class CorporateTieUp : public Payer {
    double percentage;

public:
    CorporateTieUp(double p) : percentage(p) {}

    double covered(double amount) const override {
        return amount * percentage / 100;
    }

    string name() const override {
        return "CorporateTieUp";
    }
};

int main() {

    vector<unique_ptr<Bill>> bills;

    bills.push_back(
        make_unique<OutPatient>("Ravi", 500, 1200));

    bills.push_back(
        make_unique<InPatient>("Meena", 3, 2500, 40000));

    bills.push_back(
        make_unique<RehabilitationBill>("Kiran", 8, 750));

    Insurance insurance(50000, 20);
    CorporateTieUp corporate(60);

    const Payer* payers[] = {
        &insurance,
        &corporate
    };

    for (const auto& bill : bills) {

        cout << bill->type()
             << " Total: "
             << bill->total() << endl;

        for (const Payer* p : payers) {

            cout << p->name()
                 << " Covers: "
                 << p->covered(bill->total())
                 << endl;
        }
    }

    return 0;
}