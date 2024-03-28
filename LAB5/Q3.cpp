// Write a function that takes two sorted single linked lists as input and merges them into a single
// sorted list. The original lists should remain unchanged.

#include<iostream>

using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};

ListNode* mergeLists(ListNode *head1, ListNode *head2){
    ListNode *mergedList = new ListNode;
    ListNode *temp = mergedList;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            temp->next = head1;
            head1 = head1->next;
        }else{
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if(head1 != NULL){
        temp->next = head1;
    }
    if(head2 != NULL){
        temp->next = head2;
    }
    return mergedList;
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
    ListNode *head1 = new ListNode;
    head1->data = 1;
    head1->next = new ListNode;
    head1->next->data = 3;
    head1->next->next = new ListNode;
    head1->next->next->data = 5;
    head1->next->next->next = new ListNode;
    head1->next->next->next->data = 7;
    head1->next->next->next->next = new ListNode;
    head1->next->next->next->next->data = 9;
    head1->next->next->next->next->next = NULL;

    ListNode *head2 = new ListNode;
    head2->data = 2;
    head2->next = new ListNode;
    head2->next->data = 4;
    head2->next->next = new ListNode;
    head2->next->next->data = 6;
    head2->next->next->next = new ListNode;
    head2->next->next->next->data = 8;
    head2->next->next->next->next = new ListNode;
    head2->next->next->next->next->data = 10;
    head2->next->next->next->next->next = NULL;

    cout << "List 1: " << endl;
    print(head1);

    cout << "List 2: " << endl;
    print(head2);

    ListNode *mergedList = mergeLists(head1, head2);

    cout << "Merged List: " << endl;
    print(mergedList->next);

    return 0;
}