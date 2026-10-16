#include <iostream>
using namespace std;
enum class Zone {
    Inner = 0,
    Middle = 1,
    Outer = 2,
    Airport = 3
};
constexpr long long FARES[] = {
    1000, 2000, 3000, 6000
};
constexpr long long MIN_BALANCE = 5000;
long long calculateFare(Zone z, int hour, bool weekend) {
    int index = static_cast<int>(z);
    if (index < 0 || index >= 4 ||
        hour < 0 || hour > 23)
        return -1;
    long long f = FARES[index];
    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);
    if (weekend)
        f = f * 90 / 100;
    else if (peak)
        f = f * 120 / 100;
    return f;
}
class MonthlyPass {
private:
    Zone first, second;
    bool active;
public:
    MonthlyPass(Zone a, Zone b)
        : first(a), second(b), active(true) {}

    bool covers(Zone z) const {
        return active && (z == first || z == second);
    }
};
class SmartCard {
private:
    long long balance;
public:
    SmartCard(long long b) : balance(b) {}
    bool canTravel(long long fare) const {
        return fare >= 0 &&
               balance - fare >= MIN_BALANCE;
    }
    bool pay(long long fare) {
        if (!canTravel(fare))
            return false;
        balance -= fare;
        return true;
    }
    long long getBalance() const {
        return balance;
    }
};
int main() {
    SmartCard card(20000);
    MonthlyPass pass(Zone::Inner, Zone::Middle);
    cout << "Airport weekday peak fare paise: "
         << calculateFare(Zone::Airport, 18, false) << '\n';
    cout << "Airport weekend fare paise: "
         << calculateFare(Zone::Airport, 18, true) << '\n';
    cout << boolalpha;
    cout << "Pass covers Inner: "
         << pass.covers(Zone::Inner) << '\n';
    cout << "Pass covers Airport: "
         << pass.covers(Zone::Airport) << '\n';
    long long f = calculateFare(Zone::Airport, 18, false);
    cout << "Airport payment accepted: "
         << card.pay(f) << '\n';
    cout << "Remaining balance paise: "
         << card.getBalance() << '\n';
    return 0;
}