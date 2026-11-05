#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "Hello ";
    string b = "World!";

    string c = a + b;

    cout << c << endl;
    cout << boolalpha << (a == b) << endl;

    return 0;
}