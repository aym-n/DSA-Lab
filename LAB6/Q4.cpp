#include<iostream>
#include<stdio.h>

using namespace std;

struct ListNode{
    int data;
    ListNode *next;
};

class queue{
    public:
        int size;
        ListNode* front;
        ListNode* rear;

        queue(){
            size = 0;
            front = NULL;
            rear = NULL;
        }

        int isEmpty(){
            return size == 0;
        }

        void enqueue(int data){
            ListNode* newNode = new ListNode();
            newNode->data = data;
            newNode->next = NULL;
            if(isEmpty()){
                front = newNode;
            }else{
                rear->next = newNode;
            }
            rear = newNode;
            size++;
        }

        int dequeue(){
            if(isEmpty()){
                cout << "Queue Underflow" << endl;
                return __INT_MAX__;
            }
            int data = front->data;
            ListNode* temp = front;
            front = front->next;
            delete temp;
            size--;
            return data;
        }

        int peek(){
            if(isEmpty()){
                cout << "Queue Underflow" << endl;
                return __INT_MAX__;
            }
            return front->data;
        }

        ~queue(){
            ListNode* temp;
            while(front != NULL){
                temp = front;
                front = front->next;
                delete temp;
            }
        }
};

int main(){
    /*
    OUTPUT:
    1
    2
    3
    1
    Queue Underflow
    2147483647
    1
    */
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;
    cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}