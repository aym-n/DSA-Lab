#include<iostream>

using namespace std;
struct Date{
    int day;
    int month;
    int year;
};

struct Employee{
    string EmployeeID;
    string name;
    string department;
    string designation;
    Date dateOfJoining;
    Date dateOfBirth;
    int salary;
};

void printEmployee(Employee e){
    cout << "Employee ID: " << e.EmployeeID << endl;
    cout << "Name: " << e.name << endl;
    cout << "Department: " << e.department << endl;
    cout << "Designation: " << e.designation << endl;
    cout << "Date of Joining: " << e.dateOfJoining.day << "/" << e.dateOfJoining.month << "/" << e.dateOfJoining.year << endl;
    cout << "Date of Birth: " << e.dateOfBirth.day << "/" << e.dateOfBirth.month << "/" << e.dateOfBirth.year << endl;
    cout << "Salary: " << e.salary << endl;
}

int numberOfEmployees(Employee e[]){
    return 5;
}

void printEmployee(Employee e[], Date date){
    for(int i = 0; i < numberOfEmployees(e); i++){
        if(e[i].dateOfJoining.year > date.year){
            printEmployee(e[i]);
        }
        else if(e[i].dateOfJoining.year == date.year){
            if(e[i].dateOfJoining.month > date.month){
                printEmployee(e[i]);
            }
            else if(e[i].dateOfJoining.month == date.month){
                if(e[i].dateOfJoining.day > date.day){
                    printEmployee(e[i]);
                }
            }
        }
    }
}

void searchEmployee(Employee e[], string employeeID){
    for(int i = 0; i < numberOfEmployees(e); i++){
        if(e[i].EmployeeID == employeeID){
            printEmployee(e[i]);
        }
    }
}

void updateSalary(Employee e, int salary){
    e.salary = salary;
}

void deleteEmployee(Employee e[], string employeeID){
    for(int i = 0; i < numberOfEmployees(e); i++){
        if(e[i].EmployeeID == employeeID){
            for(int j = i; j < 4; j++){
                e[j] = e[j + 1];
            }
            break;
        }
    }
}

int averageSalary(Employee e[]){
    int sum = 0;
    int count = numberOfEmployees(e);
    for(int i = 0; i < count; i++){
        sum += e[i].salary;
    }
    return sum / count;
}

int maxSalary(Employee e[]){
    int max = e[0].salary;
    int count = numberOfEmployees(e);
    for(int i = 1; i < count; i++){
        if(e[i].salary > max){
            max = e[i].salary;
        }
    }
    return max;
}

int minSalary(Employee e[]){
    int min = e[0].salary;
    int count = numberOfEmployees(e);
    for(int i = 1; i < count; i++){
        if(e[i].salary < min){
            min = e[i].salary;
        }
    }
    return min;
}

int main(){

    Employee e[5] = {
        {"E001", "John Doe", "HR", "Manager", {1, 1, 2010}, {1, 1, 1980}, 10000},
        {"E002", "Jane Doe", "HR", "Manager", {1, 1, 2011}, {1, 1, 1981}, 11000},
        {"E003", "John Smith", "HR", "Manager", {1, 1, 2012}, {1, 1, 1982}, 12000},
        {"E004", "Jane Smith", "HR", "Manager", {1, 1, 2013}, {1, 1, 1983}, 13000},
        {"E005", "John Doe", "HR", "Manager", {1, 1, 2014}, {1, 1, 1984}, 14000}
    };

    printEmployee(e, {1, 1, 2012});
    searchEmployee(e, "E004");
    updateSalary(e[0], 15000);
    deleteEmployee(e, "E002");
    cout << "Average Salary: " << averageSalary(e) << endl;
    cout << "Max Salary: " << maxSalary(e) << endl;
    cout << "Min Salary: " << minSalary(e) << endl;
    printEmployee(e[0]);
    return 0;
}
