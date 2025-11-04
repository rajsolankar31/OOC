#include <iostream>
using namespace std;


class SavingAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;
    double interestRate;

public:
    SavingAccount(string name, int accNumber, double initialBalance, double rate) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
        interestRate = rate;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdraw: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest Applied: " << interest << endl;
    }

    void display() {
        cout << "\n(Savings Account)" << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
    }
};


class CheckingAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;
    double transactionFee;

public:
    CheckingAccount(string name, int accNumber, double initialBalance, double fee) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
        transactionFee = fee;
    }

    void deposit(double amount) {
        balance += amount;
        balance -= transactionFee;
        cout << "Deposited: " << amount << " Fee: " << transactionFee << endl;
    }

    void withdraw(double amount) {
        if (amount + transactionFee <= balance) {
            balance -= (amount + transactionFee);
            cout << "Withdraw: " << amount << " Fee: " << transactionFee << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display() {
        cout << "\n(Checking Account)" << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
    }
};


int main() {
	
    cout << "Name  : Raj Solankar\n";
    cout << "Roll No: 128\n";
    cout << "Class : S.Y. B. CSE\n";
    
    SavingAccount sav("raj", 1001, 5000.0, 5.0);
    CheckingAccount chk("raj", 1002, 10000.0, 20.0);

    sav.display();
    sav.deposit(1000);
    sav.withdraw(2000);
    sav.applyInterest();

    chk.display();
    chk.deposit(500);
    chk.withdraw(1000);

    return 0;
}