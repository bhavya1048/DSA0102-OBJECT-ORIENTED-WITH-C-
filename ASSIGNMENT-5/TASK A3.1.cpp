#include <iostream>
#include <algorithm>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() = default;
};

class Payer {
public:
    virtual double amountCovered(
        const Bill& b) const = 0;

    virtual ~Payer() = default;
};

class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return 0;
    }
};

class Insurance : public Payer {
    double limit, copay;

public:
    Insurance(double l, double c)
        : limit(l), copay(c) {}

    double amountCovered(const Bill& b) const override {
        return min(b.total(), limit)
               * (1 - copay / 100);
    }
};

class GovernmentScheme : public Payer {
    double rate;

public:
    GovernmentScheme(double r) : rate(r) {}

    double amountCovered(const Bill& b) const override {
        return min(b.total(), rate);
    }
};

class SampleBill : public Bill {
public:
    double total() const override {
        return 50000;
    }
};

int main() {
    SampleBill bill;

    SelfPay s;
    Insurance i(40000, 20);
    GovernmentScheme g(30000);

    cout << "SelfPay: "
         << s.amountCovered(bill) << endl;

    cout << "Insurance: "
         << i.amountCovered(bill) << endl;

    cout << "Government: "
         << g.amountCovered(bill) << endl;
}