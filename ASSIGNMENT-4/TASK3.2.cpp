#include <iostream>
#include <string>
using namespace std;

class Address {
    string city;

public:
    Address(string c) : city(c) {}

    void display() {
        cout << "City: " << city << endl;
    }
};

class Person {
protected:
    string name;
    Address address;

public:
    Person(string n, string c)
        : name(n), address(c) {}
};

class Course {
    string courseName;

public:
    Course(string c) : courseName(c) {}

    void display() {
        cout << "Course: " << courseName << endl;
    }
};

class Student : public Person {
    Course course;

public:
    Student(string n, string c, string co)
        : Person(n, c), course(co) {}

    void display() {
        cout << "Name: " << name << endl;
        address.display();
        course.display();
    }
};

int main() {
    Student s("Kavya", "Salem", "C++");
    s.display();
    return 0;
}