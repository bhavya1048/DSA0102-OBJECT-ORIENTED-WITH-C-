#include <iostream>
using namespace std;

class SavingsAccount {
private:
    int accountNo;
    double balance;
    double transactions[10];
    int count;

    void record(double amount) {
        if (count < 10) {
            transactions[count++] = amount;
        } else {
            for (int i = 1; i < 10; i++)
                transactions[i - 1] = transactions[i];

            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(int no, double bal) {
        accountNo = no;
        balance = bal;
        count = 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            record(amount);
        }
    }

    void withdraw(double amount);
    void miniStatement() const;
};

void SavingsAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        record(-amount);
    }
}

void SavingsAccount::miniStatement() const {
    cout << "Account Number: " << accountNo << '\n';
    cout << "Balance: " << balance << '\n';
    cout << "Transactions:\n";

    for (int i = 0; i < count; i++)
        cout << transactions[i] << '\n';
}

int main() {
    int no;
    double balance, amount;
    int choice;

    cout << "Enter account number: ";
    cin >> no;
    cout << "Enter initial balance: ";
    cin >> balance;

    SavingsAccount a(no, balance);

    cout << "1. Deposit  2. Withdraw  3. Statement  0. Exit\n";

    do {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter amount: ";
            cin >> amount;
            a.deposit(amount);
        } else if (choice == 2) {
            cout << "Enter amount: ";
            cin >> amount;
            a.withdraw(amount);
        } else if (choice == 3) {
            a.miniStatement();
        }
    } while (choice != 0);

    return 0;
}