// Write a function to find the intersection of two singly linked lists. If the lists do not
// intersect, return null.


#include <iostream>

using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB){
    ListNode *a = headA;
    ListNode *b = headB;

    while(a != b){
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }

    return a;
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
    ListNode *headA = new ListNode;
    headA->data = 1;
    headA->next = new ListNode;
    headA->next->data = 2;
    headA->next->next = new ListNode;
    headA->next->next->data = 3;
    headA->next->next->next = new ListNode;
    headA->next->next->next->data = 4;
    headA->next->next->next->next = new ListNode;
    headA->next->next->next->next->data = 5;
    headA->next->next->next->next->next = NULL;

    ListNode *headB = new ListNode;
    headB->data = 6;
    headB->next = new ListNode;
    headB->next->data = 7;
    headB->next->next = headA->next->next->next;

    cout << "List A: " << endl;
    print(headA);

    cout << "List B: " << endl;
    print(headB);

    ListNode *intersection = getIntersectionNode(headA, headB);

    if(intersection != NULL){
        cout << "Intersection Node: " << intersection->data << endl;
    }else{
        cout << "No Intersection" << endl;
    }

    return 0;
}

