#include<iostream>

using namespace std;

// Given an unsorted array of elements and a key value, write a function to determine if the key
// exists in the array.

int main(){
   int arr[]  = {1 , 5, 6, 9, 18, 2};
   int size = sizeof(arr)/sizeof(arr[0]);

    int target = 2;

   for(int i = 0; i < size; i++){
    if(arr[i] == target){
        cout<<target<<" found on index "<<i<<endl;
        return 0;
    }
   } 
   cout << target << " not found"<<endl;
   return 0;  
}