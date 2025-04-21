/*
    Programmer : Rahul Rangani
    Aim        : To develop a system that calculates and displays EMI for loan applicants
    Date       : 14 February, 2025
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Loan class to store loan details and calculate EMI
class Loan
{
private:
    string loanID;         // Unique ID for the loan
    string applicantName;  // Name of the person applying for the loan
    double principal;      // Loan amount
    double annualRate;     // Annual interest rate
    int tenureMonths;      // Tenure in months
    double emi;            // Monthly EMI

public:
    // Constructor to initialize all values and calculate EMI
    Loan(string id, string name, double amount, double rate, int tenure)
    {
        loanID = id;
        applicantName = name;
        principal = amount;
        annualRate = rate;
        tenureMonths = tenure;
        emi = calculateEMI(); // EMI is calculated at the time of object creation
    }

    // Method to calculate EMI using standard EMI formula
    double calculateEMI()
    {
        double R = annualRate / (12 * 100); // Monthly interest rate
        int T = tenureMonths;

        double numerator = principal * R * pow(1 + R, T);
        double denominator = pow(1 + R, T) - 1;

        return numerator / denominator; // Returning EMI value
    }

    // Method to display complete loan details
    void displaySummary()
    {
        cout << fixed << setprecision(2); // Set output precision to 2 decimal places
        cout << "\n--- Loan Summary ---" << endl;
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: Rs. " << principal << endl;
        cout << "Annual Interest Rate: " << annualRate << "%" << endl;
        cout << "Tenure: " << tenureMonths << " months" << endl;
        cout << "Monthly EMI: Rs. " << emi << endl;
    }
};

int main()
{
    // Create a loan object using sample test data
    Loan testLoan("LN001", "John Doe", 500000, 7.5, 60);
    testLoan.displaySummary(); // Display predefined loan

    // Variables to take user input
    string id, name;
    double amount, rate;
    int months;

    // Get loan details from user
    cout << "\nEnter new loan details:\n";
    cout << "Loan ID: ";
    cin >> id;
    cin.ignore(); // To ignore leftover newline character
    cout << "Applicant Name: ";
    getline(cin, name);
    cout << "Loan Amount: ";
    cin >> amount;
    cout << "Annual Interest Rate (%): ";
    cin >> rate;
    cout << "Tenure (in months): ";
    cin >> months;

    // Create a new Loan object with user-provided data
    Loan userLoan(id, name, amount, rate, months);
    userLoan.displaySummary(); // Display user-entered loan info

    // Optionally display EMI again using method call
    cout << "\nAccessed directly from public method: EMI = Rs. "
         << fixed << setprecision(2)
         << userLoan.calculateEMI() << endl;

    cout << endl;
    cout << "Rahul Rangani :: 24CE102" << endl;

    return 0;
}
