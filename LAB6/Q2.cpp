#include<iostream>
#include<stdio.h>

using namespace std;

struct ListNode{
    int data;
    ListNode *next;
};


class stack{
    public:
        int size;
        ListNode* top;

        stack(){
            size = 0;
            top = NULL;
        }

        void push(int data){
            ListNode* newNode = new ListNode();
            newNode->data = data;
            newNode->next = top;
            top = newNode;
            size++;
        }

        int isEmpty(){
            return size == 0;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return __INT_MAX__;
            }
            int data = top->data;
            ListNode* temp = top;
            top = top->next;
            delete temp;
            size--;
            return data;
        }

        int peek(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return __INT_MAX__;
            }
            return top->data;
        }

        int peep(int i){
            if(i >= size){
                cout << "Index out of bounds" << endl;
                return __INT_MAX__;
            }
            ListNode* temp = top;
            for(int j = 0; j < i; j++){
                temp = temp->next;
            }
            return temp->data;
        }

        ~stack(){
            ListNode* temp;
            while(top != NULL){
                temp = top;
                top = top->next;
                delete temp;
            }
        }

        void display() {
            ListNode* temp = top;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    /*
    OUTPUT:
    3
    2
    1
    Stack Underflow
    2147483647
    */
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}