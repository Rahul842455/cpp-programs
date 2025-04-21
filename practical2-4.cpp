/*
    Programmer : Rahul Rangani
    Aim : Build a system for efficient inventory tracking and stock management
    Date : 14 February, 2025
*/

#include <iostream>
using namespace std;

// Item class to represent inventory items
class Item
{
private:
    int item_id;           // Item ID
    string item_name;      // Item name
    double item_price;     // Item price
    int item_quantity;     // Item quantity in stock

public:
    // Constructor with default values
    Item(int id = 0, string n = "Unknown", double p = 0.0, int q = 0)
        : item_id(id), item_name(n), item_price(p), item_quantity(q) {}

    // Method to add stock
    void addItem(int q)
    {
        if (q > 0)
        {
            item_quantity += q;
            cout << "Item added successfully!" << endl;
            cout << "New quantity: " << item_quantity << endl;
        }
        else
        {
            cout << "Invalid quantity!" << endl;
        }
    }

    // Method to sell stock
    void sellItem(int q)
    {
        if (q > 0 && item_quantity >= q)
        {
            item_quantity -= q;
            cout << "Item sold successfully!" << endl;
            cout << "New quantity: " << item_quantity << endl;
        }
        else
        {
            cout << "Invalid quantity!" << endl;
        }
    }

    // Method to display item details
    void display()
    {
        cout << "Item Details:" << endl;
        cout << "ID: " << item_id << endl;
        cout << "Name: " << item_name << endl;
        cout << "Price: " << item_price << endl;
        cout << "Quantity: " << item_quantity << endl;
    }

    // Method to return item ID
    int getID()
    {
        return item_id;
    }
};

int main()
{
    int choice, id, q;

    // Creating 3 items (0th is unused, 1st and 2nd are pre-defined)
    Item items[3] =
    {
        Item(),                                   // Default item (unused)
        Item(101, "Mobile", 1000, 10),            // Mobile
        Item(102, "Power Bank", 550, 10)          // Power Bank
    };

    // Menu-driven loop
    do
    {
        // Display menu
        cout << "1. Add Items\n2. Sell Items\n3. Display Details\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Add items
            cout << "Enter the ID of the item: ";
            cin >> id;
            cout << "Enter the quantity to add: ";
            cin >> q;

            if (id == 101 || id == 102)
            {
                items[id - 100].addItem(q);  // Access appropriate item
            }
            else
            {
                cout << "Invalid item ID!" << endl;
            }
            break;

        case 2: // Sell items
            cout << "Enter the ID of the item: ";
            cin >> id;
            cout << "Enter the quantity to sell: ";
            cin >> q;

            if (id == 101 || id == 102)
            {
                items[id - 100].sellItem(q);  // Access appropriate item
            }
            else
            {
                cout << "Invalid item ID!" << endl;
            }
            break;

        case 3: // Display item details
            for (int i = 1; i < 3; i++)
            {
                items[i].display();
                cout << "------------------------" << endl;
            }
            break;

        case 4: // Exit the program
            cout << "Exiting the program.." << endl;
            break;

        default: // Invalid choice
            cout << "Invalid Input. Try again." << endl;
            break;
        }
    }
    while (choice != 4);    // Continue until user chooses to exit

    cout << endl;
    cout << "Rahul Rangani :: 24CE102" << endl;

    return 0;
}
