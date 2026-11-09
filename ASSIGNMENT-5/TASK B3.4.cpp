
#include <iostream>
using namespace std;

class Bill {
public:
    virtual double total() = 0;
    virtual ~Bill() {}
};

class OP : public Bill {
public:
    double total() {
        return 1700;
    }
};

class IP : public Bill {
public:
    double total() {
        return 47500;
    }
};

int main() {
    OP outpatient;
    IP inpatient;

    Bill *bills[2];

    bills[0] = &outpatient;
    bills[1] = &inpatient;

    double sum = 0;

    for (int i = 0; i < 2; i++) {
        cout << "Bill Total: " << bills[i]->total() << endl;
        sum += bills[i]->total();
    }

    cout << "Overall Total: " << sum << endl;

    return 0;
}
