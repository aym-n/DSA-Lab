// Implement the Merge Sort algorithm as a function that takes an array of integers and sorts it.

#include<iostream>
#include<climits>

using namespace std;

void merge(int arr[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1], R[n2 + 1];

    for(int i = 0; i < n1; i++){
        L[i] = arr[p + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[q + j + 1];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    for(int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int arr[], int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main(){
    int arr[] = {5, 2, 4, 7, 1, 3, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

