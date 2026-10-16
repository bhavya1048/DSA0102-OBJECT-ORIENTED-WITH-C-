#include <iostream>
#include <climits>
using namespace std;
int main() {
    cout << "Size of int: " << sizeof(int) << '\n';
    cout << "Size of long long: " << sizeof(long long) << '\n';
    cout << "INT_MAX: " << INT_MAX << '\n';
    long long totalPaise = 3000000LL * 3600;
    cout << "Total paise: " << totalPaise << '\n';
    cout << "Total rupees: " << totalPaise / 100 << '\n';
    return 0;
}