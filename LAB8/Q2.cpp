// Given a list of people's heights and the number of people in front of each person who have a
// height greater than or equal to theirs, reconstruct the queue to arrange the people based on
// non-decreasing order of their height.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number of people: ";
    cin>>n;

    queue<int> q;
    queue<int>buffer;

    for(int i=0; i<n; i++){
        int height, infront;
        cout<<"Enter the height of person "<<i+1<<": ";
        cin>>height;

        while(q.size() && q.front() < height){
            buffer.push(q.front());
            q.pop();
        }

        q.push(height);

        while(buffer.size()){
            q.push(buffer.front());
            buffer.pop();
        }
    }

    cout<<"The queue is: ";
    while(q.size()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}