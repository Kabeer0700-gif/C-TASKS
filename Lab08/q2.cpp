#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accNumber;
    float balance;
public:
    Account(int n = 0, float b = 0) {
        accNumber = n;
        balance = b;
    }
    friend class Manager;
};

class Manager {
public:
    void display(Account acc) {
        cout << "Account Number: " << acc.accNumber << ", Balance: " << acc.balance << endl;
    }

    void deposit(Account& acc, float amount) {
        acc.balance += amount;
    }

    void withdraw(Account& acc, float amount) {
        if (acc.balance >= amount)
            acc.balance -= amount;
        else
            cout << "Insufficient Balance!" << endl;
    }

    void transferFunds(Account& from, Account& to, float amount) {
        if (from.balance >= amount) {
            from.balance -= amount;
            to.balance += amount;
            cout << "Transfer Successful!" << endl;
        } else {
            cout << "Insufficient Balance to Transfer!" << endl;
        }
    }
};

int main() {
    Account a1(101, 1000), a2(102, 500);
    Manager m;

    m.display(a1);
    m.display(a2);

    m.deposit(a1, 200);
    m.withdraw(a2, 100);

    m.display(a1);
    m.display(a2);

    m.transferFunds(a1, a2, 300);

    m.display(a1);
    m.display(a2);

    return 0;
}
