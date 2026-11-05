#include <iostream>
using namespace std;

class Staff {
    int type;
    double basic, research, hours, rate;

public:
    Staff(int t, double b, double r, double h, double rt)
        : type(t), basic(b), research(r), hours(h), rate(rt) {}

    double pay() {
        switch (type) {
            case 1: return basic + basic * 0.42 + research;
            case 2: return basic + basic * 0.42;
            case 3: return hours * rate;
            default: return 0;
        }
    }
};

int main() {
    Staff s(1, 30000, 5000, 0, 0);
    cout << "Salary: " << s.pay();
    return 0;
}