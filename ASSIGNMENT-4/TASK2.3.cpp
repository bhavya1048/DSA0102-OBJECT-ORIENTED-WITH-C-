#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int id;
    string phone;

    Person(string n = "", int i = 0, string p = "")
        : name(n), id(i), phone(p) {}
};

class Student : virtual public Person {
public:
    string programme;
    float cgpa;

    Student(string n = "", int i = 0, string p = "",
            string pr = "", float c = 0)
        : Person(n, i, p), programme(pr), cgpa(c) {}
};

class Staff : virtual public Person {
public:
    string department;
    double salary;

    Staff(string n = "", int i = 0, string p = "",
          string d = "", double s = 0)
        : Person(n, i, p), department(d), salary(s) {}
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p,
                      string pr, float c, string d, double s)
        : Person(n, i, p),
          Student(n, i, p, pr, c),
          Staff(n, i, p, d, s) {}
};

class ResearchScholar : public Student {
public:
    double fellowship;

    ResearchScholar(string n, int i, string p,
                    string pr, float c, double f)
        : Person(n, i, p),
          Student(n, i, p, pr, c), fellowship(f) {}
};

int main() {
    TeachingAssistant ta("Kavya", 101, "9876543210",
                         "CSE", 9.1, "IT", 25000);

    cout << "Name: " << ta.name << endl;
    cout << "Programme: " << ta.programme << endl;
    cout << "Department: " << ta.department << endl;

    return 0;
}