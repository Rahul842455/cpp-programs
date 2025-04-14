/* Programmer : Rahul Rangani
   Aim : To develop an efficient inventory management system using either procedural or OOP approach
   Date : 07 February, 2025
*/

#include<iostream>
using namespace std;

// Product class to represent each product in the inventory
class Product
{
public:
    int id;
    string name;
    int quantity;
    float price;

    // Method to input product details from the user
    void add_product()
    {
        cout << "Enter the id of the product: ";
        cin >> id;
        cout << "Enter the name of the product: ";
        cin >> name;
        cout << "Enter the quantity of the product: ";
        cin >> quantity;
        cout << "Enter the price of the product: ";
        cin >> price;
    }

    // Method to update product quantity
    void update(int newQuantity)
    {
        quantity = newQuantity;
    }

    // Method to calculate total price for the product
    float calculation()
    {
        float p;
        p = price * quantity;
        return p;
    }
};

int main()
{
    Product P[3];              // Array to store 3 products
    int i, newid, newQuantity; // Variables for loop, product ID, and updated quantity
    float total_value = 0.0;   // Variable to store total inventory value

    // Loop to input details of each product
    for(i = 0; i < 3; i++)
    {
        cout << "(" << i+1 << ") Product Details:: \n";
        P[i].add_product();
    }

    // Ask user if they want to update any product
    cout << "For updation enter 1: ";
    cin >> i;

    if(i == 1)
    {
        // Input ID of product to update
        cout << "Enter the id of the existing product: ";
        cin >> newid;

        // Search for the product with given ID and update quantity
        for(i = 0; i < 3; i++)
        {
            if(P[i].id == newid)
            {
                cout << "Enter the remaining quantity of this existing product: ";
                cin >> newQuantity;
                P[i].update(newQuantity);
            }
        }
    }

    // Calculate total value of all products
    for(i = 0; i < 3; i++)
    {
        total_value += P[i].calculation();
    }

    // Display the total inventory value
    cout << "The total value of all the product is: " << total_value;

    cout << endl;
    cout << "Rahul Rangani :: 24CE102" << endl;

    return 0;
}
