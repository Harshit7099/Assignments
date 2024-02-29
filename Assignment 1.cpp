#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
    string userId;
    string password;
    double balance;

public:
    BankAccount() {
        userId = "";
        password = "";
        balance = 0.0;
    }

    void createAccount() {
        cout << "Please enter your user id: ";
        cin >> userId;
        cout << "Please enter your password: ";
        cin >> password;
        cout << "Thank You! Your account has been created!" << endl;
    }

    bool login() {
        string inputUserId, inputPassword;
        cout << "Please enter your user id: ";
        cin >> inputUserId;
        cout << "Please enter your password: ";
        cin >> inputPassword;

        if (inputUserId == userId && inputPassword == password) {
            cout << "Access Granted!" << endl;
            return true;
        } else {
            cout << "******** LOGIN FAILED! ********" << endl;
            return false;
        }
    }

    void deposit() {
        double amount;
        cout << "Amount of deposit: $";
        cin >> amount;
        balance += amount;
    }

    void withdraw() {
        double amount;
        cout << "Amount of withdrawal: $";
        cin >> amount;
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void requestBalance() {
        cout << "Your balance is $" << balance << endl;
    }
};

int main() {
    BankAccount account;
    char choice;

    cout << "Hi! Welcome to Mr. Zamar's ATM Machine!" << endl;

    while (true) {
        cout << "Please select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;
        cout << "> ";
        cin >> choice;

        switch (choice) {
            case 'l':
                if (account.login()) {
                    char transactionChoice;
                    do {
                        cout << "d -> Deposit Money" << endl;
                        cout << "w -> Withdraw Money" << endl;
                        cout << "r -> Request Balance" << endl;
                        cout << "> ";
                        cin >> transactionChoice;

                        switch (transactionChoice) {
                            case 'd':
                                account.deposit();
                                break;
                            case 'w':
                                account.withdraw();
                                break;
                            case 'r':
                                account.requestBalance();
                                break;
                            case 'q':
                                cout << "Thanks for stopping by!" << endl;
                                return 0;
                            default:
                                cout << "Invalid choice!" << endl;
                        }
                    } while (transactionChoice != 'q');
                }
                break;
            case 'c':
                account.createAccount();
                break;
            case 'q':
                cout << "Thanks for stopping by!" << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
