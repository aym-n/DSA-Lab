// Modify the Quick Sort implementation to randomly select the pivot element instead of always
// choosing the last element as the pivot. Implement a function that chooses a random pivot for
// each partitioning step. Evaluate the performance of the randomized Quick Sort algorithm and
// compare it with the standard Quick Sort.
// • Print the partition details
// • Execution time in terms of microseconds on a relatively large input array generated
// using random number generator.


#include<iostream>
#include<climits>
#include<chrono>

using namespace std;

int partition(int arr[], int p, int r){
    int i = p - 1;
    int pivot = arr[r];
    swap(arr[pivot], arr[r]);
    pivot = arr[r];
    for(int j = p; j < r; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int partitionRandom(int arr[], int p, int r){
    int i = p - 1;
    int pivot = rand() % (r - p + 1) + p;
    swap(arr[pivot], arr[r]);
    pivot = arr[r];
    for(int j = p; j < r; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSortRandom(int arr[], int p, int r){
    if(p < r){
        int q = partitionRandom(arr, p, r);
        quickSortRandom(arr, p, q - 1);
        quickSortRandom(arr, q + 1, r);
    }
}

void quickSort(int arr[], int p, int r){
    if(p < r){
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

void populateArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 1000;
    }
}

int main(){
    int n = 100000;
    int arr[n];
    populateArray(arr, n);

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();

    auto startRandom = chrono::high_resolution_clock::now();
    quickSortRandom(arr, 0, n - 1);
    auto endRandom = chrono::high_resolution_clock::now();

    cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
    cout << "Execution time (random): " << chrono::duration_cast<chrono::microseconds>(endRandom - startRandom).count() << " microseconds" << endl;
    cout << "Difference: " << chrono::duration_cast<chrono::microseconds>(end - start).count() - chrono::duration_cast<chrono::microseconds>(endRandom - startRandom).count() << " microseconds" << endl;

    return 0;
}