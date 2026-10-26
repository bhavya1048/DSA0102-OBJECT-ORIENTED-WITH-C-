#include <iostream>
using namespace std;

class SavingsAccount {
private:
    double balance;
    double transactions[50];
    int start, count;

    void record(double amount) {
        if (count < 50) {
            transactions[(start + count) % 50] = amount;
            count++;
        } else {
            transactions[start] = amount;
            start = (start + 1) % 50;
        }
    }

public:
    SavingsAccount(double b) {
        balance = b;
        start = 0;
        count = 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            record(amount);
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            record(-amount);
        }
    }

    void miniStatement() const {
        cout << "Balance: " << balance << '\n';
        cout << "Recent transactions:\n";

        for (int i = 0; i < count; i++)
            cout << transactions[(start + i) % 50] << '\n';
    }
};

int main() {
    double initial, amount;
    int n;

    cout << "Enter initial balance: ";
    cin >> initial;

    SavingsAccount account(initial);

    cout << "Enter number of deposits: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter deposit amount: ";
        cin >> amount;
        account.deposit(amount);
    }

    account.miniStatement();

    return 0;
}