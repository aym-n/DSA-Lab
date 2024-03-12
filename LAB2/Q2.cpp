#include <iostream>

using namespace std;

// Given a sorted array of elements and a key value, write a function to determine if the key
// exists in the array.

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    int size = sizeof(arr) / sizeof(arr[0]);

    int left = size - 1;
    int right = 0;
    int target = 4;

    while (right >= left)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            cout << target << "found at index" << mid << endl;
            return 0;
        }
        else if (arr[mid] < target)
            right = mid + 1;
        else
            left = mid - 1;
    }

    cout << target << "not found" << endl;
    return 0;
}