#include <iostream>
#include <stdexcept>
using namespace std;

void validateCharge(double amount) {
    if (amount < 0)
        throw invalid_argument("Negative charge");
}

void cleanup() noexcept {
    cout << "Resources released";
}

int main() {
    try {
        validateCharge(-100);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cleanup();
}