#include <iostream>
using namespace std;
class SmartCard {
    long long balance;
public:
    SmartCard(long long b) {
        balance = b;
    }
    bool canTravel(long long fare) {
        return fare >= 0 && balance - fare >= 5000;
    }
    bool deduct(long long fare) {
        if (canTravel(fare)) {
            balance -= fare;
            return true;
        }
        return false;
    }
    long long getBalance() {
        return balance;
    }
};
int main() {
    SmartCard card(10000);
    cout << boolalpha << card.deduct(2000) << '\n';
    cout << card.getBalance() << " paise\n";
    return 0;
}