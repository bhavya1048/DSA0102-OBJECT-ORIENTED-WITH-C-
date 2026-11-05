#include <iostream>
using namespace std;

class Person {
public:
    string name;

    Person(string n) : name(n) {}
};

class Student : public Person {
public:
    Student(string n) : Person(n) {}
};

class Staff : public Person {
public:
    Staff(string n) : Person(n) {}
};

class TeachingAssistant {
public:
    Student student;
    Staff staff;

    TeachingAssistant(string n)
        : student(n), staff(n) {}
};

int main() {
    TeachingAssistant ta("Kavya");

    cout << ta.student.name << endl;
    cout << ta.staff.name << endl;

    cout << "Size: " << sizeof(ta) << endl;
    return 0;
}