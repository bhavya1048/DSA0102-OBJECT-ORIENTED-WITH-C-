#include <iostream>
using namespace std;
constexpr long long MIN_BALANCE = 5000;
bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= MIN_BALANCE;
}
long long proceduralDeduct(long long balance, long long fare) {
    if (proceduralCanTravel(balance, fare))
        return balance - fare;
    return balance;
}
class SmartCard {
private:
    long long balance;
public:
    SmartCard(long long b) {
        balance = b;
    }
    bool canTravel(long long fare) {
        return fare >= 0 && balance - fare >= MIN_BALANCE;
    }
    bool deduct(long long fare) {
        if (!canTravel(fare))
            return false;
        balance -= fare;
        return true;
    }
    long long getBalance() {
        return balance;
    }
};
int main() {
    long long balance = 10000;
    balance = proceduralDeduct(balance, 2000);
    cout << "Procedural balance: " << balance << '\n';
    SmartCard card(10000);
    card.deduct(2000);
    cout << "OOP balance: " << card.getBalance() << '\n';
    return 0;
}