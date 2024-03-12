#include<iostream>

using namespace std;

// Design a program to manage employee records using structures in C++. The program should
// provide the following functionalities:
// • Add new employee records with the following details: Employee ID, Name,
//     Department, Designation, DoB, DoJ, Salary
// • Display all employee records.
// • Display all the employees who have joined before/after a specific Date.
// • Search for an employee by their ID and display their details.
// • Update an employee's salary.
// • Delete an employee record by their ID.
// • Calculate and display the following:
// o Total number of employees
// o Average salary
// o Highest and lowest salaries

// Ensure that the program implements proper error handling and validation for user inputs. Use
// appropriate data structures and algorithms to manage and manipulate employee records
// efficiently.

struct Employee
{
    int id;
    string name;
    string department;
    string designation;
    Date dob;
    Date doj;
    double salary;
};

class Date{
    public:
    int day;
    int month;
    int year;
    public:
    Date(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }
    bool operator < (Date d){
        if(year < d.year)
            return true;
        else if(year == d.year && month < d.month)
            return true;
        else if(year == d.year && month == d.month && day < d.day)
            return true;
        return false;
    }
    bool operator > (Date d){
        if(year > d.year)
            return true;
        else if(year == d.year && month > d.month)
            return true;
        else if(year == d.year && month == d.month && day > d.day)
            return true;
        return false;
    }
};


int main(){
    Employee employees[100];
    int count = 0;
    while(true){
        cout << "1. Add new employee records" << endl;
        cout << "2. Display all employee records" << endl;
        cout << "3. Display all the employees who have joined before/after a specific Date" << endl;
        cout << "4. Search for an employee by their ID and display their details" << endl;
        cout << "5. Update an employee's salary" << endl;
        cout << "6. Delete an employee record by their ID" << endl;
        cout << "7. Calculate and display the following:" << endl;
        cout << "8. Exit" << endl;
        int choice;
        cin >> choice;
        if(choice == 1){
            cout << "Enter Employee ID: ";
            cin >> employees[count].id;
            cout << "Enter Employee Name: ";
            cin >> employees[count].name;
            cout << "Enter Employee Department: ";
            cin >> employees[count].department;
            cout << "Enter Employee Designation: ";
            cin >> employees[count].designation;
            cout << "Enter Employee Date of Birth (dd mm yyyy): ";
            int d, m, y;
            cin >> d >> m >> y;
            employees[count].dob = Date(d, m, y);
            cout << "Enter Employee Date of Joining (dd mm yyyy): ";
            cin >> d >> m >> y;
            employees[count].doj = Date(d, m, y);
            cout << "Enter Employee Salary: ";
            cin >> employees[count].salary;
            count++;
        }
        else if(choice == 2){
            for(int i = 0; i < count; i++){
                cout << "Employee ID: " << employees[i].id << endl;
                cout << "Employee Name: " << employees[i].name << endl;
                cout << "Employee Department: " << employees[i].department << endl;
                cout << "Employee Designation: " << employees[i].designation << endl;
                cout << "Employee Date of Birth: " << employees[i].dob.day << "/" << employees[i].dob.month << "/" << employees[i].dob.year << endl;
                cout << "Employee Date of Joining: " << employees[i].doj.day << "/" << employees[i].doj.month << "/" << employees[i].doj.year << endl;
                cout << "Salary: "<< employees[i].salary << endl;
            }
        }else if(choice == 3){
            for(int i = 0; i < count; i++){
                if(employees[i].doj < Date(1, 1, 2000)){
                    cout << "Employee ID: " << employees[i].id << endl;
                    cout << "Employee Name: " << employees[i].name << endl;
                    cout << "Employee Department: " << employees[i].department << endl;
                    cout << "Employee Designation: " << employees[i].designation << endl;
                    cout << "Employee Date of Birth: " << employees[i].dob.day << "/" << employees[i].dob.month << "/" << employees[i].dob.year << endl;
                    cout << "Employee Date of Joining: " << employees[i].doj.day << "/" << employees[i].doj.month << "/" << employees[i].doj.year << endl;
                    cout << "Salary: "<< employees[i].salary << endl;
                }
            }
        }else if(choice == 4){
            int id;
            cout << "Enter Employee ID: ";
            cin >> id;
            for(int i = 0; i < count; i++){
                if(employees[i].id == id){
                    cout << "Employee ID: " << employees[i].id << endl;
                    cout << "Employee Name: " << employees[i].name << endl;
                    cout << "Employee Department: " << employees[i].department << endl;
                    cout << "Employee Designation: " << employees[i].designation << endl;
                    cout << "Employee Date of Birth: " << employees[i].dob.day << "/" << employees[i].dob.month << "/" << employees[i].dob.year << endl;
                    cout << "Employee Date of Joining: " << employees[i].doj.day << "/" << employees[i].doj.month << "/" << employees[i].doj.year << endl;
                    cout << "Salary: "<< employees[i].salary << endl;
                }
            }

        }else if(choice == 5){
            int id;
            cout << "Enter Employee ID: ";
            cin >> id;
            for(int i = 0; i < count; i++){
                if(employees[i].id == id){
                    cout << "Enter new salary: ";
                    cin >> employees[i].salary;
                }
            }
        }else if(choice == 6){

            int id;
            cout << "Enter Employee ID: ";
            cin >> id;
            for(int i = 0; i < count; i++){
                if(employees[i].id == id){
                    for(int j = i; j < count - 1; j++){
                        employees[j] = employees[j + 1];
                    }
                    count--;
                }
            }

        }else if(choice == 7){
            double total = 0;
            double max = employees[0].salary;
            double min = employees[0].salary;
            for(int i = 0; i < count; i++){
                total += employees[i].salary;
                if(employees[i].salary > max)
                    max = employees[i].salary;
                if(employees[i].salary < min)
                    min = employees[i].salary;
            }
            cout << "Total number of employees: " << count << endl;
            cout << "Average salary: " << total / count << endl;
            cout << "Highest salary: " << max << endl;
            cout << "Lowest salary: " << min << endl;
        }else if(choice == 8){
            break;
        }
}

