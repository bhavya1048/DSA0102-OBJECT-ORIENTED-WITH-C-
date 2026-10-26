#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
    int h, m;

public:
    Time(int hh, int mm) {
        h = hh;
        m = mm;
    }

    friend int minutesBetween(const Time&, const Time&);
    friend bool earlier(const Time&, const Time&);
};

inline int minutesBetween(const Time& a, const Time& b) {
    int x = a.h * 60 + a.m;
    int y = b.h * 60 + b.m;
    return abs(x - y);
}

inline bool earlier(const Time& a, const Time& b) {
    return a.h * 60 + a.m < b.h * 60 + b.m;
}

int main() {
    int h1, m1, h2, m2;

    cout << "Enter first time (hour minute): ";
    cin >> h1 >> m1;

    cout << "Enter second time (hour minute): ";
    cin >> h2 >> m2;

    Time t1(h1, m1), t2(h2, m2);

    cout << "Difference in minutes: "
         << minutesBetween(t1, t2) << '\n';

    cout << boolalpha;
    cout << "First time is earlier: "
         << earlier(t1, t2) << '\n';

    return 0;
}