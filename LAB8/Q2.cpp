#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    queue<int> q1, q2;
    int n;
    cout<<"Enter the number of elements in the queue: ";
    cin>>n;

    for(int i = 0; i < n; i++){
        int x;
        cout<<"Enter element "<<i+1<<": ";
        cin>>x;

        while(!q1.empty() && q1.front() < x){
            q2.push(q1.front());
            q1.pop();
        }

        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        while(!q2.empty()){
            cout<<q2.front()<<" ";
            q1.push(q2.front());
            q2.pop();
        }

        cout<<endl;
    }

    return 0;

}