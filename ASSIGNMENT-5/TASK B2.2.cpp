
#include <iostream>
using namespace std;

bool approve(double bill, double cover, double &approved) {
    if (bill < 0 || cover < 0 || bill > cover) {
        return false;
    }

    approved = bill;
    return true;
}

int main() {
    double approved = 0;

    if (approve(40000, 50000, approved)) {
        cout << "Approved: " << approved << endl;
    }
    else {
        cout << "Rejected" << endl;
    }

    if (approve(60000, 50000, approved)) {
        cout << "Approved: " << approved << endl;
    }
    else {
        cout << "Rejected" << endl;
    }

    return 0;
}
