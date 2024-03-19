// Implement a strategy to terminate the selection sorting process early if the array becomes
// sorted before completing all iterations. Track whether swaps were made in each iteration and
// stop sorting if no swaps occur. [Recollect the bubble sort algorithm discussed in the class]

#include<iostream>

using namespace std;

int selectionSort(int arr[], int n){
    int swaps = 0;
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
    return swaps;
}

int main(){
    int arr[] = {1, 8, 9 , 2, 1, 5, 6, 9, 18, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    int swaps = selectionSort(arr, size);
    cout<<"Swaps: "<<swaps<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }  
    cout<<endl;
    return 0;
}