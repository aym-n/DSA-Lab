// Modify the Quick Sort implementation to handle arrays with duplicate elements efficiently
// using three-way partitioning. Implement a function that partitions the array into three parts:
// elements less than the pivot, elements equal to the pivot, and elements greater than the
// pivot.

#include<iostream>
#include<climits>

using namespace std;

int partitionRight(int arr[], int p, int r){
    int x = arr[r];
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(arr[j] < x){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int partitionLeft(int arr[], int p, int r){
    int x = arr[p];
    int i = r + 1;
    for(int j = r; j > p; j--){
        if(arr[j] > x){
            i--;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i - 1], arr[p]);
    return i - 1;
}

void quickSort(int arr[], int p, int r){
    if(p < r){
        int q = partitionRight(arr, p, r);
        int s = partitionLeft(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, s + 1, r);
    }
}

int main(){
    int arr[] = {5, 2, 4, 7, 1, 3, 5, 6, 3, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
