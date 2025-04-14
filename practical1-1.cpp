/* Programmer : Rahul Rangani
   Aim : To create a secure OOP-based banking system for managing accounts
   Date : 07 February, 2025
*/

#include <iostream>
#include <string>
using namespace std;

// BankAccount class definition
class BankAccount
{
    // Private data members for encapsulation
    string accountHolderName;
    long int accountNumber;
    long int balance;

public:

    // Method to get initial account details from user
    void getAccountDetails()
    {
        cout << "Enter the name of account holder: ";
        cin.ignore(); // To clear any leftover newline character from input buffer
        getline(cin, accountHolderName);

        cout << "Enter the account number: ";
        cin >> accountNumber;

        cout << "Enter the current balance of this account: ";
        cin >> balance;
    }

    // Method to deposit an amount into the account
    void deposit(long int amount)
    {
        balance += amount;
        cout << "Amount deposited: " << amount << endl;
    }

    // Method to withdraw an amount from the account
    void withdraw(long int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    // Method to display current balance
    void displayBalance() const
    {
        cout << "Your current balance is: " << balance << endl;
    }
};

int main()
{
    BankAccount b1;
    long int amount;

    // Get user account details
    b1.getAccountDetails();

    // Deposit section
    cout << "Enter the amount you want to deposit: ";
    cin >> amount;
    b1.deposit(amount);

    // Withdraw section
    cout << "Enter the amount you want to withdraw: ";
    cin >> amount;
    b1.withdraw(amount);

    // Display final balance
    b1.displayBalance();

    cout << endl;
    cout << "Rahul Rangani :: 24CE102" << endl;

    return 0;
}
