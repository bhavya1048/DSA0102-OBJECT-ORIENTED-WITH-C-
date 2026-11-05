
#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char* data;

public:
    Text(const char* s = "") {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    // Copy constructor
    Text(const Text& t) {
        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
    }

    // Copy assignment
    Text& operator=(const Text& t) {
        if (this != &t) {
            char* temp = new char[strlen(t.data) + 1];
            strcpy(temp, t.data);
            delete[] data;
            data = temp;
        }
        return *this;
    }

    // Concatenation
    Text operator+(const Text& t) const {
        char* temp = new char[strlen(data) + strlen(t.data) + 1];

        strcpy(temp, data);
        strcat(temp, t.data);

        Text result(temp);
        delete[] temp;
        return result;
    }

    bool operator==(const Text& t) const {
        return strcmp(data, t.data) == 0;
    }

    bool operator!=(const Text& t) const {
        return !(*this == t);
    }

    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    ~Text() {
        delete[] data;
    }
};

int main() {
    Text a("Hello ");
    Text b("World!");

    Text c = a + b;

    cout << "Message: " << c << endl;

    Text empty("");
    cout << "Empty: " << empty << endl;

    cout << boolalpha;
    cout << "Equal: " << (a == b) << endl;

    Text d("Hello ");
    d = d;
    cout << "Self Assignment: " << d << endl;

    return 0;
}
