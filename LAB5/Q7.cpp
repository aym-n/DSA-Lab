// Write an O(n) time function to determine if a single linked list is a palindrome.

#include<iostream>
#include<stack>

using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};


bool isPalindrome(ListNode *head){
    ListNode *curr = head;
    stack<int> s;
    while(curr != NULL){
        s.push(curr->data);
        curr = curr->next;
    }

    while(head != NULL){
        int top = s.top();
        s.pop();
        if(head->data != top){
            return false;
        }
        head = head->next;
    }

    return true;
}

int main(){
    ListNode *head = new ListNode;
    head->data = 1;
    head->next = new ListNode;
    head->next->data = 2;
    head->next->next = new ListNode;
    head->next->next->data = 3;
    head->next->next->next = new ListNode;
    head->next->next->next->data = 2;
    head->next->next->next->next = new ListNode;
    head->next->next->next->next->data = 1;
    head->next->next->next->next->next = NULL;

    cout << "Is Palindrome: " << isPalindrome(head) << endl;

    return 0;
}
