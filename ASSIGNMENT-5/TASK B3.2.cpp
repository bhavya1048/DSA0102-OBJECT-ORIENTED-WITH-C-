#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {

    const int N = 1000000;

    auto start = high_resolution_clock::now();

    double total = 0;

    for (int i = 0; i < N; i++)
        total += 500 + 1200;

    auto stop = high_resolution_clock::now();

    auto duration =
        duration_cast<milliseconds>(stop - start);

    cout << "Total: " << total << endl;
    cout << "Execution Time: "
         << duration.count() << " ms";
}