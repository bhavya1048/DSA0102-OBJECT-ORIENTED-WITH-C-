#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Prescription {
    vector<string> medicines;

public:
    Prescription(int n) : medicines(n) {}

    void set(int i, string m) {
        medicines[i] = m;
    }

    void display() {
        for (string m : medicines)
            cout << m << " ";
    }
};

int main() {
    Prescription p(2);
    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;
    q.display();
}