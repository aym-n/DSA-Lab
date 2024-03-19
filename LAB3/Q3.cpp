// Modify the insertion sort implementation to employ binary search to find the correct position
// of the element to be placed in the sorted subarray to decrease the # of comparisons required.
// Run the native and modified insertion sort on the same inputs and assess the performance of
// the modified algorithm under different data distributions.

#include<iostream>

using namespace std;
void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        // Binary search to find the correct position of the element to be placed in the sorted subarray
        int l = 0, r = i - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(arr[mid] < key){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        for(int j = i - 1; j >= l; j--){
            arr[j + 1] = arr[j];
        }
        arr[l] = key;
    }
}

int main(){
    int arr[] = {5, 2, 4, 6, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}