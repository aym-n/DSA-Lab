// Write a program to create a single linked list. Include methods to insert elements at the
// beginning, end, a specific position of the list, and a specific element of the list, delete
// elements, search for a value, and display the contents of the list.

#include<iostream>
#include<stdio.h>

using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};

class SinglyLinkedList{
    public:
        struct ListNode *head;
        SinglyLinkedList(){
            head = NULL;
        }

        /* List Traversal O(n)*/
        void print(){
            struct ListNode *temp = head;
            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }

        int length(){
            ListNode *temp = head;
            int count = 0;
            while(temp != NULL){
                count++;
                temp = temp->next;
            }
            return count;
        }

        /* Insertion at begining O(1) */
        ListNode* insertAtBegining(int data){
            ListNode *newNode = new ListNode;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
            return head;
        }

        /* Insertion at end O(n) */

        ListNode* insertAtEnd(int data){
            ListNode *newNode = new ListNode;
            newNode->data = data;
            newNode->next = NULL;

            // head does't exist set the new node as heads
            if(head == NULL){
                head = newNode;
                return head;
            }
            ListNode *temp = head;

            // traverse to the end of the list
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            return head;
        }

        /* Insertion at a given position O(n) */
        ListNode* insertAtPosition(int data, int position){
            ListNode *newNode = new ListNode;
            newNode->data = data;
            newNode->next = NULL;

            if(position < 0 || position > length()){
                cout << "Invalid Position" << endl;
                return head;
            }

            if(position == 0){
                insertAtBegining(data);
            }

            ListNode *temp = head;
            for(int i = 0; i < position - 1; i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }

        /* Deletion at begining O(1) */
        ListNode* deleteAtBegining(){
            if(head == NULL){
                cout << "List is empty" << endl;
                return head;
            }
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        /* Deletion at end O(n) */
        ListNode* deleteAtEnd(){
            if(head == NULL){
                cout << "List is empty" << endl;
                return head;
            }
            ListNode *temp = head;
            ListNode *prev = NULL;
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
            return head;
        }

        /* Deletion at a given position O(n) */
        ListNode* deleteAtPosition(int position){
            if(position < 0 || position > length()){
                cout << "Invalid Position" << endl;
                return head;
            }

            if(position == 0){
                deleteAtBegining();
            }

            ListNode *temp = head;
            ListNode *prev = NULL;
            for(int i = 0; i < position; i++){
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
            return head;
        }

        int Search(int value){
            ListNode *temp = head;
            int position = 0;
            while(temp != NULL){
                if(temp->data == value){
                    return position;
                }
                position++;
                temp = temp->next;
            }
            return -1;
        }

        // Q5 Write a function to find the middle node of a single linked list. If the list contains an even
        // number of nodes, return the second middle node.

        ListNode* middleNode(){
            ListNode *slow = head;
            ListNode *fast = head;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        // Q9 Write a program to check if the list is in non-decreasing order or not.

        bool isNonDecreasing(){
            ListNode *temp = head;
            while(temp->next != NULL){
                if(temp->data > temp->next->data){
                    return false;
                }
                temp = temp->next;
            }
            return true;
        }

        // Q8 Define the function moveToFront(struct node *head) to move a last node to the front of a single linked list.
        ListNode* moveToFront(){
            ListNode *temp = head;
            ListNode *prev = NULL;
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            temp->next = head;
            head = temp;
            return head;
        }
};

int main(){
    SinglyLinkedList sll;
    sll.insertAtBegining(10);
    sll.insertAtBegining(20);
    sll.insertAtBegining(30);
    sll.insertAtBegining(40);
    sll.insertAtEnd(50);
    sll.insertAtEnd(60);
    sll.insertAtEnd(70);
    sll.insertAtPosition(100, 3);
    sll.print();
    // Output: 40 -> 30 -> 100 -> 20 -> 10 -> 50 -> 60 -> 70 -> NULL

    sll.deleteAtEnd();
    sll.deleteAtBegining();
    sll.deleteAtPosition(3);
    sll.print();
    // Output: 30 -> 100 -> 10 -> 50 -> 60 -> NULL

    cout << "Length of the list: " << sll.length() << endl;
    // Length of the list: 8

    cout << "Position of 100: " << sll.Search(100) << endl;
    // Output: 1

    cout << "Middle Node: " << sll.middleNode()->data << endl;
    // Output: 10

    return 0;
}

