// Modify the Merge Sort implementation to sort an array of strings in lexicographical order.
// Write a function that takes an array of strings as input and sorts it using Merge Sort.


#include<iostream>
#include<climits>

using namespace std;

void merge(string arr[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    string L[n1 + 1], R[n2 + 1];

    for(int i = 0; i < n1; i++){
        L[i] = arr[p + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[q + j + 1];
    }

    L[n1] = CHAR_MAX;
    R[n2] = CHAR_MAX;

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

void mergeSort(string arr[], int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main(){
    string arr[] = {"apple", "banana", "mango", "grapes", "orange", "kiwi", "papaya", "guava"};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

