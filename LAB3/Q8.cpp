// Implement the radix sort algorithm to sort an array of positive integers in ascending order.
// Modify the radix sort implementation to sort an array of strings in lexicographical order.

#include<iostream>

using namespace std;

int getMax(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int size, int place){
    int output[size];
    int count[10] = {0};

    for(int i = 0; i < size; i++) count[arr[i] / place % 10]++;
    int position = 0;
    for(int i = 0; i < 10; i++){
        while(count[i] > 0){
            output[position] = i;
            count[i]--;
            position++;
        }
    }

    for(int i = 0; i < size; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n){
    int max = getMax(arr, n);
    int place = 0;
    while(max > 0){
        countingSort(arr, n, ++place);
        max /= 10;
    }
}

int main(){
    int arr[] = {12, 15, 95 , 21, 15, 52, 65, 91, 11, 25};
    int size = sizeof(arr)/sizeof(arr[0]);
    countingSort(arr, size, 2);

    for(int i = 0; i < size; i++) cout<<arr[i]<<" ";
    return 0;
}