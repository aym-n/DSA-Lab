// Implement the Radix Sort algorithm that handles input arrays with a mix of positive and
// negative integers.

#include<iostream>

using namespace std;

int getMax(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp){
    int output[n];
    int count[10] = {0};
    for(int i = 0; i < n; i++){
        count[(arr[i] / exp) % 10]++;
    }
    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    for(int i = n - 1; i >= 0; i--){
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n){
    int posArr[n], negArr[n];
    int posIndex = 0, negIndex = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] >= 0){
            posArr[posIndex++] = arr[i];
        }else{
            negArr[negIndex++] = -arr[i];
        }
    }

    int maxPos = getMax(posArr, posIndex);
    int maxNeg = getMax(negArr, negIndex);

    for(int exp = 1; maxPos / exp > 0; exp *= 10){
        countingSort(posArr, posIndex, exp);
    }

    for(int exp = 1; maxNeg / exp > 0; exp *= 10){
        countingSort(negArr, negIndex, exp);
    }

    int posIndex2 = 0, negIndex2 = 0;
    for(int i = 0; i < n; i++){
        if(i < negIndex){
            arr[i] = -negArr[negIndex - 1 - negIndex2++];
        }else{
            arr[i] = posArr[posIndex2++];
        }
    }
}

int main(){
    int arr[] = {10, 14, -12, 22, -74, 52, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}



