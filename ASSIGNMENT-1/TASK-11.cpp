#include <iostream>
using namespace std;
constexpr long long MIN_BALANCE = 5000;
long long calculateFare(int zone, int hour) {
    if (zone < 1 || zone > 3 || hour < 0 || hour > 23)
        return -1;
    long long fare = zone * 1000;
    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20))
        fare += fare * 20 / 100;
    return fare;
}
int main() {
    int zone, hour;
    long long balance;
    cout << "Enter zone (1=Inner, 2=Middle, 3=Outer): ";
    cin >> zone;
    cout << "Enter hour (0-23): ";
    cin >> hour;
    cout << "Enter balance in paise: ";
    cin >> balance;
    long long fare = calculateFare(zone, hour);
    if (fare < 0) {
        cout << "Invalid input";
    } else {
        cout << "Fare in paise: " << fare << '\n';
        if (balance - fare >= MIN_BALANCE)
            cout << "Journey allowed";
        else
            cout << "Journey denied";
    }
    return 0;
}