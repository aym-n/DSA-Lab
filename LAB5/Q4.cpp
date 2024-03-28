// Write a function to remove the nth node from the end of a single linked list and return the head of the list.

#include<iostream>

using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};

ListNode* removeNthFromEnd(ListNode *head, int n){
    ListNode *dummy = new ListNode;
    dummy->next = head;
    ListNode *first = dummy;
    ListNode *second = dummy;

    for(int i = 1; i <= n+1; i++){
        first = first->next;
    }

    while(first != NULL){
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;
    return dummy->next;
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

    head = removeNthFromEnd(head, 2);

    cout << "List after removing 2nd node from end: " << endl;
    print(head);

    return 0;
}