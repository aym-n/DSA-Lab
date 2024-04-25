// Given a number n, generate the number n in binary using queue

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number of binary numbers to generate: ";
    cin>>n;

    queue<string> q;
    q.push("1");
    for(int i=0; i<n; i++){
        string s1 = q.front();
        q.pop();
        cout<<s1<<endl;
        string s2 = s1;
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }  

    return 0;  
}