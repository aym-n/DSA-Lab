// Write a function to find all peak elements from an array of integers. A peak element is an
// element that is greater than or equal to its neighbours. Consider that the input array is
// wrapped around.
// Sample Array: 100, 20, 15, -2, 23, 90, 67
// Peak elements: 100, 90

#include <iostream>

using namespace std;

void findPeaks(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= arr[(i - 1 + size) % size] && arr[i] >= arr[(i + 1) % size])
            cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {100, 20, 15, -2, 23, 90, 67};

    int size = sizeof(arr) / sizeof(arr[0]);

    findPeaks(arr, size);

    return 0;
}