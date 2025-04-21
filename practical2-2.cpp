/*
    Programmer : Rahul Rangani
    Aim : To store, display, and analyze student records
    Date : 14 February, 2025
*/

#include<iostream>
using namespace std;

// Student class definition
class Student
{
    int roll_no;          // Student roll number
    double marks[3];      // Marks in 3 subjects
    string name;          // Student name

public:
    // Default constructor
    Student(): roll_no(0), name("Default name"), marks{100, 100, 100}
    {
        cout << "Saving default student details.." << endl;
    }

    // Parameterized constructor
    Student(int r, string n, double m[])
    {
        roll_no = r;
        name = n;
        marks[0] = m[0];
        marks[1] = m[1];
        marks[2] = m[2];
    }

    // Function to calculate average of 3 marks
    double calculateAverage()
    {
        return (marks[0] + marks[1] + marks[2]) / 3;
    }

    // Function to display student details
    void displayDetails()
    {
        cout << "\nStudent Details::" << endl;
        cout << "Roll No.:: " << roll_no << endl;
        cout << "Name :: " << name << endl;
        cout << "Average marks :: " << calculateAverage() << endl;
    }
};

int main()
{
    // Create default student object
    Student defalutStudent;
    cout << "Displaying the default student details::" << endl;
    defalutStudent.displayDetails();

    // Variables to store input for specific student
    int r;
    string n;
    double m[3];

    // Get student details from user
    cout << "Enter roll number: ";
    cin >> r;

    cout << "Enter the name: ";
    cin>>n;


    cout << "Enter the marks of three subjects: ";
    cin >> m[0] >> m[1] >> m[2];

    // Create object with specific student details
    Student specificStudent(r, n, m);

    // Display specific student details
    cout << "Displaying the specific student details::" << endl;
    specificStudent.displayDetails();

    cout << endl;
    cout << "Rahul Rangani :: 24ce102" << endl;

    return 0;
}
