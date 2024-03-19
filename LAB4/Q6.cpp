// Use Quick sort to develop an algorithm to find median of an array of integers. The median of
// a set of numbers is the middle value when the numbers are arranged in ascending or
// descending order.

#include <iostream>

using namespace std;

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSortMedian(int arr[], int p, int r, int index, bool found = false)
{
    if (p < r){
        int q = partition(arr, p, r);
        int n = r - p + 1;
        if(!found && q == index ) {
            cout << "Median: " << arr[q] << endl;
            found = true;
        }
        quickSortMedian(arr, q + 1, r, index, found);
        quickSortMedian(arr, p, q - 1, index, found);
    }

}

int main()
{
    int arr[] = {1, 2, 4, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSortMedian(arr, 0, n - 1, n/2);
    return 0;
}