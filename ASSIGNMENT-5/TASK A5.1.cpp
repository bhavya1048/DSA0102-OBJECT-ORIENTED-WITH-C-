#include <iostream>
#include <stdexcept>
using namespace std;

void processClaim() {
    try {
        throw runtime_error("Claim rejected");
    }
    catch (const exception& e) {
        cout << "Log: " << e.what() << endl;
        throw;
    }
}

int main() {
    try {
        processClaim();
    }
    catch (const exception& e) {
        cout << "User Message: "
             << e.what() << endl;
    }
}