#include <iostream>
#include <string>
using namespace std;

class Address {
    string city;

public:
    Address(string c) : city(c) {}

    string getCity() const {
        return city;
    }
};

class Student {
    Address* home;

public:
    Student(string c) {
        home = new Address(c);
    }

    Student(const Student& s) {
        home = new Address(*s.home);
    }

    Student& operator=(const Student& s) {
        if (this != &s) {
            *home = *s.home;
        }
        return *this;
    }

    void display() {
        cout << home->getCity() << endl;
    }

    ~Student() {
        delete home;
    }
};

int main() {
    Student s("Salem");
    Student s2 = s;

    s.display();
    s2.display();

    return 0;
}