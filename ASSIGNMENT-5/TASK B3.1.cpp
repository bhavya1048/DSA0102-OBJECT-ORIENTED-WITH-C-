#include <iostream>
using namespace std;

struct Bill {
    int type;
    double a, b;
    int days;
};

double switchTotal(const Bill& x) {

    switch(x.type) {

        case 1:
            return x.a + x.b;

        case 2:
            return x.a * x.days + x.b;

        default:
            return 0;
    }
}

int main() {

    Bill bills[10];

    for (int i = 0; i < 10; i++) {

        if (i % 2 == 0)
            bills[i] = {1, 500, 1200, 0};
        else
            bills[i] = {2, 2500, 10000, 2};
    }

    double sum = 0;

    for (int i = 0; i < 10; i++)
        sum += switchTotal(bills[i]);

    cout << "Switch Total: " << sum;
}