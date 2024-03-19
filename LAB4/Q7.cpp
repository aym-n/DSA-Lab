// Implement the Quick Sort algorithm as a function that takes an array of integers and sorts it.

#include<iostream>

using namespace std;

int partitions(int arr[], int p, int r) {
    int pivot = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int median(int arr[], int p, int r, int index) {
    if (p < r) {
        int q = partitions(arr, p, r);
        if (q == index) {
            return q;
        } else if (q < index) {
            return median(arr, q + 1, r, index);
        } else {
            return median(arr, p, q - 1, index);
        }
    }
    return p;
}

int partition(int arr[], int p, int r){
    int x = median(arr, p, r, (r - p + 1) / 2);
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(arr[j] <= x){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int arr[], int p, int r){
    if(p < r){
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main(){
    int arr[] = {5, 2, 4, 7, 1, 3, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}