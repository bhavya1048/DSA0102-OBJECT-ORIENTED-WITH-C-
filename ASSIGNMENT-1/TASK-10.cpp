#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    const long long n = 3000000;
    const long long farePaise = 3600;
    long long totalPaise = n * farePaise;
    double totalRupees = n * 36.0;
    cout << "Integer-paise total: " << totalPaise << '\n';
    cout << "Integer total rupees: " << totalPaise / 100 << '\n';
    cout << fixed << setprecision(2);
    cout << "Double total rupees: " << totalRupees << '\n';
    return 0;
}