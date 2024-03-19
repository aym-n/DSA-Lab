// Self-study: Write a function to find the median of an array of integers using the Median of
// Medians algorithm. Employ this median of medians finding algorithm to revise the quick sort
// implementation. Compare the performance of the following quick sort implementation.
// • Choose first element as pivot
// • Choose last element as pivot
// • Choose random element as pivot
// • Choose median as pivot

#include<iostream>
#include<climits>
#include<chrono>
#include<algorithm>

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

int partitionFirst(int arr[], int p, int r){
    int i = p - 1;
    int pivot = arr[p];
    for(int j = p; j < r; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[p]);
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

void quickSort(int arr[], int p, int r){
    if(p < r){
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

void quickSortFirst(int arr[], int p, int r){
    if(p < r){
        int q = partitionFirst(arr, p, r);
        quickSortFirst(arr, p, q - 1);
        quickSortFirst(arr, q + 1, r);
    }
}

void quickSortRandom(int arr[], int p, int r){
    if(p < r){
        int q = partitionRandom(arr, p, r);
        quickSortRandom(arr, p, q - 1);
        quickSortRandom(arr, q + 1, r);
    }
}

int findMedian(int arr[], int p, int r) {
    int n = r - p + 1;
    int numMedians = (n + 4) / 5;
    int *medians = new int[numMedians];

    for (int i = 0; i < numMedians; i++) {
        int start = p + i * 5;
        int end = min(p + (i + 1) * 5 - 1, r);
        sort(arr + start, arr + end + 1);
        medians[i] = arr[(start + end) / 2];
    }

    if (numMedians == 1) {
        delete[] medians;
        return arr[p];
    } else {
        return findMedian(medians, 0, numMedians - 1);
    }
}

int medianOfMedians(int arr[], int p, int r) {
    if (p == r) return arr[p];

    int median = findMedian(arr, p, r);
    int pivotIndex = partition(arr, p, r);
    if (arr[pivotIndex] == median) {
        return pivotIndex;
    } else if (arr[pivotIndex] < median) {
        return medianOfMedians(arr, pivotIndex + 1, r);
    } else {
        return medianOfMedians(arr, p, pivotIndex - 1);
    }
}

int partitionMedian(int arr[], int p, int r){
    int x = arr[medianOfMedians(arr, p, r)];
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

void quickSortMedian(int arr[], int p, int r){
    if(p < r){
        int q = partitionMedian(arr, p, r);
        quickSortMedian(arr, p, q - 1);
        quickSortMedian(arr, q + 1, r);
    }
}

void populateArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 1000;
    }
}

int main(){
    int n = 1000;
    int arr[n];
    populateArray(arr, n);

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    cout << "Time taken for quickSort: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    populateArray(arr, n);
    start = chrono::high_resolution_clock::now();
    quickSortFirst(arr, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    cout << "Time taken for quickSortFirst: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    populateArray(arr, n);
    start = chrono::high_resolution_clock::now();
    quickSortRandom(arr, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    cout << "Time taken for quickSortRandom: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    populateArray(arr, n);
    start = chrono::high_resolution_clock::now();
    quickSortMedian(arr, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    cout << "Time taken for quickSortMedian: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}




