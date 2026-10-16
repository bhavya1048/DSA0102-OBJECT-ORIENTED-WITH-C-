#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
int main() {
    int hour;
    cout << "Enter hour (0-23): ";
    while (!(cin >> hour) || hour < 0 || hour > 23) {
        cout << "Invalid hour. Enter an integer from 0 to 23: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    long long farePaise = 3600;
    cout << fixed << setprecision(2);
    cout << "Fare: Rs " << farePaise / 100.0 << '\n';
    cout << "Fare in paise: " << farePaise << '\n';
    return 0;
}