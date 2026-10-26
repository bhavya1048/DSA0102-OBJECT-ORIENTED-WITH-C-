#include <iostream>
using namespace std;

int& highest(int marks[], int n) {
    int best = 0;

    for (int i = 1; i < n; i++) {
        if (marks[i] > marks[best])
            best = i;
    }

    return marks[best];
}

int main() {
    int n, marks[100];

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    highest(marks, n) += 2;

    cout << "Updated marks:\n";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";

    cout << '\n';
    return 0;
}