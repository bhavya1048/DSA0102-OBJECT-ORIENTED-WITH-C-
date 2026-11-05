
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    Money operator+(const Money& m) const {
        return Money(0, paise + m.paise);
    }

    Money operator-(const Money& m) const {
        return Money(0, paise - m.paise);
    }

    Money& operator+=(const Money& m) {
        paise += m.paise;
        return *this;
    }

    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    bool operator<(const Money& m) const {
        return paise < m.paise;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        out << (m.paise < 0 ? "-Rs " : "Rs ")
            << m.absAmount() / 100 << "."
            << setw(2) << setfill('0') << m.absAmount() % 100;
        return out;
    }

    friend istream& operator>>(istream& in, Money& m) {
        long long r;
        int p;
        in >> r >> p;
        if (in)
            m.paise = r * 100 + p;
        return in;
    }

private:
    long long absAmount() const {
        return llabs(paise);
    }
};

int main() {
    Money a(120, 75), b(79, 25);

    Money c = a + b;
    cout << "Total: " << c << endl;

    cout << "Difference: " << a - b << endl;

    a += b;
    cout << "After += : " << a << endl;

    cout << boolalpha;
    cout << "Equal: " << (a == c) << endl;
    cout << "Less: " << (a < c) << endl;

    Money x(0, 75), y(0, 50);
    cout << "Paise carry: " << x + y << endl;

    return 0;
}
