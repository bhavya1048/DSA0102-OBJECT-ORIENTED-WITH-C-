#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Counter {
public:
    long long value = 0;

    Counter& operator++() {
        ++value;
        return *this;
    }

    Counter operator++(int) {
        Counter old = *this;
        ++value;
        return old;
    }
};

int main() {
    Counter a, b;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < 10000000; i++)
        ++a;

    auto mid = high_resolution_clock::now();

    for (int i = 0; i < 10000000; i++)
        b++;

    auto end = high_resolution_clock::now();

    cout << "Prefix: "
         << duration<double, milli>(mid-start).count()
         << " ms\n";

    cout << "Postfix: "
         << duration<double, milli>(end-mid).count()
         << " ms\n";
}