// Given a sorted array of integers and a target value, write efficient functions to find the first
// and last occurrences of the key value in the array.
// Sample Array:

// 3 4 4 4 5 5 8 9
// 0 1 2 3 4 5 6 7

// Key value: 4
// Index of the first occurrence: 1
// Index of the last occurrence: 3

#include <iostream>

using namespace std;

int findFirstOccurrence(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            right = mid - 1;
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return result;
}

int findLastOccurrence(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            left = mid + 1;
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return result;
}

int main()
{
    int arr[] = {3, 4, 4, 4, 5, 5, 8, 9};

    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 5;

    int firstOccurrence = findFirstOccurrence(arr, size, target);
    int lastOccurrence = findLastOccurrence(arr, size, target);

    cout << "Index of the first occurrence: " << firstOccurrence << endl;
    cout << "Index of the last occurrence: " << lastOccurrence << endl;

    return 0;
}