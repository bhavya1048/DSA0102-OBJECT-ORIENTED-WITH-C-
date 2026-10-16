#include <iostream>
using namespace std;
long long baseFare(int zone) {
    if (zone == 1) return 1000;
    if (zone == 2) return 2000;
    if (zone == 3) return 3000;
    return -1;
}
bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}
long long calculateFare(int zone, int hour) {
    if (hour < 0 || hour > 23)
        return -1;
    long long f = baseFare(zone);
    if (f < 0)
        return -1;
    if (isPeak(hour))
        f += f * 20 / 100;
    return f;
}
bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= 5000;
}
int main() {
    int zone, hour;
    long long balance;
    cout << "Enter zone (1=Inner, 2=Middle, 3=Outer), "
         << "hour, balance in paise: ";
    if (!(cin >> zone >> hour >> balance)) {
        cout << "Invalid input\n";
        return 1;
    }
    long long f = calculateFare(zone, hour);
    if (f < 0) {
        cout << "Invalid zone or hour\n";
        return 1;
    }
    cout << "Fare paise: " << f << '\n';
    if (canTravel(balance, f))
        cout << "Journey allowed\n";
    else
        cout << "Journey denied\n";
    return 0;
}