#include <iostream>
using namespace std;

// Call by value
void applyConcessionValue(long long fee, int percent) {
    cout << "after call by value : " << fee << endl;
}

// Call by reference
void applyConcession(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

int main() {
    long long hostelFee = 45000;

    applyConcessionValue(hostelFee, 10);
    applyConcession(hostelFee, 10);

    cout << "after call by reference: " << hostelFee << endl;

    return 0;
}