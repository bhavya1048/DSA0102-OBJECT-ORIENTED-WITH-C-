#include <iostream>
using namespace std;

class Person {
    int id;
};

class Student : virtual public Person {};
class Staff : virtual public Person {};

class TeachingAssistant : public Student, public Staff {};

int main() {
    cout << "Size of Person: " << sizeof(Person) << endl;
    cout << "Size of TA: " << sizeof(TeachingAssistant) << endl;
    return 0;
}