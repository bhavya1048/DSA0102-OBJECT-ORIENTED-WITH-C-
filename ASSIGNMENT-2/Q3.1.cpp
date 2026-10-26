#include <iostream>
using namespace std;

double charge(double kg, bool express = false,
              bool insured = false) {
    double cost = 40 + kg * 20;

    if (express)
        cost += 30;

    if (insured)
        cost += 15;

    return cost;
}

double charge(int grams) {
    return charge(grams / 1000.0);
}

int main() {
    int grams;
    double kg;
    char express, insured;

    cout << "Enter weight in grams: ";
    cin >> grams;
    cout << "Charge: " << charge(grams) << '\n';

    cout << "Enter weight in kg: ";
    cin >> kg;

    cout << "Express delivery? (y/n): ";
    cin >> express;
    cout << "Insurance? (y/n): ";
    cin >> insured;

    cout << "Total charge: "
         << charge(kg, express == 'y', insured == 'y')
         << '\n';

    return 0;
}