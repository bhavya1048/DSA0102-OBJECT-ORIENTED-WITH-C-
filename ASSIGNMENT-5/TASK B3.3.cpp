#include <iostream>
#include <stdexcept>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {

    const int N = 1000000;

    for (int invalid = 0; invalid <= 50; invalid += 25) {

        auto start = steady_clock::now();

        int accepted = 0;

        for (int i = 0; i < N; i++) {

            double amount =
                (i < N * invalid / 100) ? -1 : 100;

            if (amount >= 0)
                accepted++;
        }

        auto stop = steady_clock::now();

        cout << invalid
             << "% invalid, accepted: "
             << accepted
             << ", time: "
             << duration_cast<milliseconds>(
                    stop - start).count()
             << " ms\n";
    }
}