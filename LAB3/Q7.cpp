// Implement the counting sort algorithm to sort an array of positive integers in ascending order.
// Also, the counting sort implementation should be modified to sort an array of characters in
// lexicographical order. Test the implementation with various strings and verify its correctness.

#include<iostream>

using namespace std;

void countingSort(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int count[max + 1] = {0};
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }
    for(int i = 1; i <= max; i++){
        count[i] += count[i - 1];
    }
    int output[n];
    for(int i = n - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void countingSort(char arr[], int n){
    int count[256] = {0};
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }
    for(int i = 1; i < 256; i++){
        count[i] += count[i - 1];
    }
    char output[n];
    for(int i = n - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

int main(){
    int arr[] = {1, 4, 1, 2, 7, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    char arr2[] = "aymanmakroo";
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    countingSort(arr2, size2);
    for(int i = 0; i < size2; i++){
        cout << arr2[i];
    }
    cout << endl;
    return 0;
}