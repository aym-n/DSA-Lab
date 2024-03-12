// Design a structure called Car with attributes such as car_ID, make, model, year,
// rental_price_per_day, from_date, and to_date. Write a program to allow users to input rental
// car data, store them in an array of structures, and then calculate and display the total rental
// cost for a particular car over a specified number of days.

#include<iostream>

using namespace std;

struct Car
{
    int car_ID;
    string make;
    string model;
    int year;
    double rental_price_per_day;
    string from_date;
    string to_date;
};

int main(){
    Car cars[100];
    int size = 0;

    while (true)
    {
        cout << "1. Add new car records" << endl;
        cout << "2. Display all car records" << endl;
        cout << "3. Calculate and display the total rental cost for a particular car over a specified number of days" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter car ID: ";
            cin >> cars[size].car_ID;

            cout << "Enter car make: ";
            cin >> cars[size].make;

            cout << "Enter car model: ";
            cin >> cars[size].model;

            cout << "Enter car year: ";
            cin >> cars[size].year;

            cout << "Enter car rental price per day: ";
            cin >> cars[size].rental_price_per_day;

            cout << "Enter car from date: ";
            cin >> cars[size].from_date;

            cout << "Enter car to date: ";
            cin >> cars[size].to_date;

            size++;
        }
        else if (choice == 2)
        {
            for (int i = 0; i < size; i++)
            {
                cout << "Car ID: " << cars[i].car_ID << endl;
                cout << "Car Make: " << cars[i].make << endl;
                cout << "Car Model: " << cars[i].model << endl;
                cout << "Car Year: " << cars[i].year << endl;
                cout << "Car Rental Price Per Day: " << cars[i].rental_price_per_day << endl;
                cout << "Car From Date: " << cars[i].from_date << endl;
                cout << "Car To Date: " << cars[i].to_date << endl;
            }
        }
        else if (choice == 3)
        {
            int carID;
            cout << "Enter car ID: ";
            cin >> carID;

            int days;
            cout << "Enter number of days: ";
            cin >> days;

            for (int i = 0; i < size; i++)
            {
                if (cars[i].car_ID == carID)
                {
                    cout << "Total rental cost: " << cars[i].rental_price_per_day * days << endl;
                }
            }
        }
        else if (choice == 4)
        {
            break;
        }
    }
}