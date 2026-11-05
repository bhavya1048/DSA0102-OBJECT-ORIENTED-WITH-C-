
#include <iomanip>
#include <iostream>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    // TODO 1: Overload +
    Money operator+(const Money& m) const {
        return Money(0, paise + m.paise);
    }

    // TODO 2: Overload == and <<
    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        out << "Rs " << m.paise / 100 << "."
            << setw(2) << setfill('0') << m.paise % 100;
        return out;
    }
};

int main() {
    Money a(120, 75), b(79, 25);
    Money c = a + b;

    cout << c << '\n'
         << boolalpha << (c == Money(200)) << '\n';
}
