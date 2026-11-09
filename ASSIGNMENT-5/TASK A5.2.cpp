#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

int main() {
    try {
        unique_ptr<int> p(new int(100));

        cout << "Value: " << *p << endl;

        throw runtime_error("Billing failed");
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }
}