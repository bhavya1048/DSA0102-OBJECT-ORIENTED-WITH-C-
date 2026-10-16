#include <iostream>
using namespace std;
enum class Zone { Inner, Middle, Outer };
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long BASE_PAISE[] = {1000, 2000, 3000};
int main() {
    cout << BASE_PAISE[0] << '\n';
    cout << BASE_PAISE[1] << '\n';
    cout << BASE_PAISE[2] << '\n';
    cout << MIN_BALANCE_PAISE << '\n';
    cout << PEAK_SURCHARGE_PERCENT << "%\n";
    return 0;
}