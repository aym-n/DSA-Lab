// Implement the insertion sort algorithm to sort an array of integers in ascending order. Modify
// the insertion sort implementation to sort an array of students’ structures [Problem statement
// 6 of Week 1] in lexicographical order (dictionary or alphabetical order) of student names.

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

void sortEmployees(Employee e[], int n){
    for(int i = 1; i < n; i++){
        Employee key = e[i];
        int j = i - 1;
        while(j >= 0 && e[j].name > key.name){
            e[j + 1] = e[j];
            j = j - 1;
        }
        e[j + 1] = key;
    }
}

void printEmployees(Employee e[], int n){
    for(int i = 0; i < n; i++){
        cout << e[i].name << ", ";
    }
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){

    Employee e[5] = {
        {"E001", "Ayman", "HR", "Manager", {1, 1, 2010}, {1, 1, 1980}, 10000},
        {"E002", "Rameez", "HR", "Manager", {1, 1, 2011}, {1, 1, 1981}, 11000},
        {"E003", "Baasit", "HR", "Manager", {1, 1, 2012}, {1, 1, 1982}, 12000},
        {"E004", "Danish", "HR", "Manager", {1, 1, 2013}, {1, 1, 1983}, 13000},
        {"E005", "Owais", "HR", "Manager", {1, 1, 2014}, {1, 1, 1984}, 14000}
    };

    int n = sizeof(e) / sizeof(e[0]);
    sortEmployees(e, n);
    printEmployees(e, n);
    return 0;
}
