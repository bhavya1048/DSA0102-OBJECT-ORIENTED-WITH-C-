#include <iostream>
using namespace std;

struct Person {
    Person() { cout << "Person "; }
    ~Person() { cout << "~Person "; }
};

struct Student : virtual Person {
    Student() { cout << "Student "; }
    ~Student() { cout << "~Student "; }
};

struct Staff : virtual Person {
    Staff() { cout << "Staff "; }
    ~Staff() { cout << "~Staff "; }
};

struct TeachingAssistant : Student, Staff {
    TeachingAssistant() { cout << "TA "; }
    ~TeachingAssistant() { cout << "~TA "; }
};

int main() {
    {
        Student s;
        cout << "| ";
    }

    {
        Staff st;
        cout << "| ";
    }

    {
        TeachingAssistant ta;
        cout << "| ";
    }

    return 0;
}