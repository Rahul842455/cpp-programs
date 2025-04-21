/*  Programmer : Rahul Rangani
    Aim : To develop a system for managing and analyzing rectangles by calculating area and perimeter
    Date : 10 February, 2025
*/

#include <iostream>
using namespace std;

// Rectangle class definition
class Rectangle
{
    float length, width, area, perimeter;

public:
    // Function to get length and width from user
    void get_dimension()
    {
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the width of the rectangle: ";
        cin >> width;
    }

    // Function to update dimensions
    void update_dimension()
    {
        cout << "Enter the new length and width of the rectangle: ";
        cin >> length >> width;
    }

    // Function to calculate area
    void calculateArea()
    {
        area = length * width;
        cout << "The area of the rectangle is: " << area << endl;
    }

    // Function to calculate perimeter
    void calculatePerimeter()
    {
        perimeter = 2 * (length + width);
        cout << "The perimeter of the rectangle is: " << perimeter << endl;
    }

    // Function to display all details
    void display()
    {
        cout << "Rectangle Length: " << length << endl;
        cout << "Rectangle Width: " << width << endl;
        cout << "Rectangle Area: " << area << endl;
        cout << "Rectangle Perimeter: " << perimeter << endl;
    }
};

int main()
{
    int num, choice;

    // Get number of rectangles from user
    cout << "Enter the number of rectangles (max 100): ";
    cin >> num;

    // Check for valid input
    if (num < 1 || num > 100)
    {
        cout << "Invalid number of rectangles. Exiting...";
        return 0;
    }

    Rectangle R[100];  // Declare array of rectangles

    // Menu-driven program
    do
    {
        // Display menu
        cout << "\nRectangle Management System" << endl;
        cout << "1. Enter the details of Rectangles" << endl;
        cout << "2. Update Rectangle Dimensions" << endl;
        cout << "3. Display All Rectangles" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Input and calculate area/perimeter for all rectangles
            for (int i = 0; i < num; i++)
            {
                cout << "\n(" << i + 1 << ") Rectangle Details: \n";
                R[i].get_dimension();
                R[i].calculateArea();
                R[i].calculatePerimeter();
            }
            break;

        case 2:
        {
            // Update specific rectangle
            int index;
            cout << "Enter the rectangle number you want to update (1-" << num << "): ";
            cin >> index;
            if (index < 1 || index > num)
            {
                cout << "Invalid rectangle number!\n";
            }
            else
            {
                R[index - 1].update_dimension();
                R[index - 1].calculateArea();
                R[index - 1].calculatePerimeter();
            }
            break;
        }

        case 3:
            // Display all rectangles
            for (int i = 0; i < num; i++)
            {
                cout << "\n(" << i + 1 << ") Rectangle Details: \n";
                R[i].display();
            }
            break;

        case 4:
            // Exit the program
            cout << "Exiting......";
            break;

        default:
            // Invalid choice
            cout << "Invalid choice! Please try again.\n";
        }
    }
    while (choice != 4);    // Repeat until user exits

    cout << endl;
    cout << "Rahul Rangani :: 24CE102" << endl;

    return 0;
}
