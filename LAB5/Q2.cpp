// Write a function to reverse a single linked list in-place. Implement an iterative solution to reverse the list.

#include<iostream>

using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};


ListNode* reverseList(ListNode *head){
    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void print(ListNode *head){
    ListNode *temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    ListNode *head = new ListNode;
    head->data = 1;
    head->next = new ListNode;
    head->next->data = 2;
    head->next->next = new ListNode;
    head->next->next->data = 3;
    head->next->next->next = new ListNode;
    head->next->next->next->data = 4;
    head->next->next->next->next = new ListNode;
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    cout << "Original List: " << endl;
    print(head);

    // Output: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

    head = reverseList(head);

    cout << "Reversed List: " << endl;
    print(head);

    // Output: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    return 0;
}