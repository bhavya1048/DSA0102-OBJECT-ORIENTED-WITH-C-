#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <new>
using namespace std;

struct Guard {
    string name;

    Guard(string n) : name(n) {
        cout << "Created " << name << endl;
    }

    ~Guard() {
        cout << "Destroyed " << name << endl;
    }
};

void validate(double amount) {
    if (amount < 0)
        throw invalid_argument("negative charge");
}

double parseAmount(string s) {
    size_t pos;
    double value = stod(s, &pos);

    if (pos != s.size())
        throw invalid_argument("invalid number");

    return value;
}

int main() {

    cout << "TEST 1: Negative charge\n";

    try {
        Guard g("negative-test");
        validate(-100);
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\nTEST 2: Invalid number\n";

    try {
        Guard g("text-test");
        cout << parseAmount("abc");
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\nTEST 3: Claim above cover\n";

    try {
        Guard g("claim-test");

        double billed = 70000;
        double cover = 50000;

        if (billed > cover)
            throw runtime_error("claim exceeds cover");
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\nTEST 4: Unknown package\n";

    try {
        Guard g("package-test");

        string code = "UNKNOWN";

        if (code != "OP001" && code != "IP001")
            throw runtime_error("unknown package");
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\nTEST 5: Memory allocation\n";

    try {
        vector<int> v;
        v.reserve(v.max_size());

        cout << "Allocation succeeded\n";
    }
    catch (const bad_alloc& e) {
        cout << "Caught bad_alloc: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Allocation error: " << e.what() << endl;
    }

    cout << "\nProgram continues safely\n";

    return 0;
}