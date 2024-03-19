// Implement the selection sort algorithm to sort an array of integers in ascending order. Modify
// the selection sort implementation to find the kth smallest element in an array.

#include<iostream>

using namespace std;

int selectionSort(int arr[], int n, int k){
    for(int i = 0; i < k; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    return arr[k-1];
}

int main(){
    int arr[] = {1, 8, 9 , 2, 1, 5, 6, 9, 18, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    int kthSmallest = selectionSort(arr, size, k);
    cout<<k<<" smallest element: "<<kthSmallest<<endl;
    return 0;
}