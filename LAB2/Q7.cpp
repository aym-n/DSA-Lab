// Given a rotated/wrapped sorted array of integers and a key value, write an efficient function
// to determine if the key value exists.
// Sample Array:

// 39 42 95 11 15 21 30 33


// Key value: 30
// Element found at index 6


#include <iostream>

using namespace std;

int findPivot(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid] < arr[left])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int binarySearchRotated(int arr[], int pivot, int target, int size){
    int left = 0;
    int right = pivot;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    left = pivot + 1;
    right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {39, 42, 95, 11, 15, 21, 30, 33};

    int size = sizeof(arr) / sizeof(arr[0]);

    int pivot = findPivot(arr, size);

    int target = 95;

    int index = binarySearchRotated(arr, pivot, target, size);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}