#include<iostream>
#include<stdio.h>
using namespace std;

class Stack {
    public:
        int size;
        int capacity;
        int *arr;
    
    Stack(int capacity = 10) {
        this->capacity = capacity;
        this->size = -1;
        this->arr = new int[capacity];
    }

    bool isEmpty() {
        return size == -1;
    }

    bool isFull() {
        return size == capacity - 1;
    }

    void push(int data) {
        if(isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++size] = data;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack Underflow" << endl;
            return __INT_MAX__;
        }
        return arr[size--];
    }

    int peek() {
        if(isEmpty()) {
            cout << "Stack Underflow" << endl;
            return __INT_MAX__;
        }
        return arr[size];
    }

    int peep(int i){
        if(i >= size){
            cout << "Index out of bounds" << endl;
            return __INT_MAX__;
        }
        return arr[i];
    }

    void deleteStack(){
        delete[] arr;
    }

    void display() {
        for(int i = 0; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    /*
    OUTPUT:
    Stack Overflow
    50
    40
    30
    20
    10
    */
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    while(!s.isEmpty()) {
        cout << s.pop() << endl;
    }
    s.deleteStack();
}