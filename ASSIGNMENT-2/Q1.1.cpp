#include <iostream>
using namespace std;

void byValue(int fee, int percent) {
    fee -= fee * percent / 100;
}

void byReference(int &fee, int percent) {
    fee -= fee * percent / 100;
}

void byPointer(int *fee, int percent) {
    *fee -= *fee * percent / 100;
}

int main() {
    int f1, f2, f3, p;

    cout << "Enter hostel fee: ";
    cin >> f1;
    f2 = f3 = f1;

    cout << "Enter concession percentage: ";
    cin >> p;

    byValue(f1, p);
    byReference(f2, p);
    byPointer(&f3, p);

    cout << "After call by value: " << f1 << '\n';
    cout << "After call by reference: " << f2 << '\n';
    cout << "After call by pointer: " << f3 << '\n';

    return 0;
}