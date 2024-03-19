// Implement the generic bubble sort algorithm to sort an array of elements in ascending order.
// Modify the bubble sort implementation to count the number of swaps made during the
// sorting process. Print the total number of swaps after sorting the array.

#include<iostream>

using namespace std;

int bubbleSort(int arr[], int n){
    int swaps = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}

int main(){
    int arr[] = {1, 8, 9 , 2, 1, 5, 6, 9, 18, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    int swaps = bubbleSort(arr, size);
    cout<<"Total number of swaps: "<<swaps<<endl;
    return 0;
}