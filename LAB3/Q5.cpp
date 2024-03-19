// Compare the performance of bubble, insertion, and selection sort algorithms based on their
// sorting time and sensitivity to the randomly generated input data distribution. Identify the
// strengths and weaknesses of each algorithm under different scenarios(i.e., random collection,
// sorted and reversely sorted).
// NOTE: Refer to the attached codes. RandomNumber_Generator.cpp for random number
// generation & Time_Required_by_Sort_Function.cpp for finding the time consumed by the
// sorting logic.

#include<iostream>
#include<chrono>

using namespace std;

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

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

void populateArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 1000;
    }
}

int main(){
    int size = 10000;
    int arr[size];
    populateArray(arr, size);
    int k = 3;

    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Time taken by bubble sort: " << elapsed.count() << " s" << endl;

    populateArray(arr, size);
    start = chrono::high_resolution_clock::now();
    insertionSort(arr, size);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by insertion sort: " << elapsed.count() << " s" << endl;

    populateArray(arr, size);
    start = chrono::high_resolution_clock::now();
    selectionSort(arr, size, k);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by selection sort: " << elapsed.count() << " s" << endl;

    return 0;
}


