// Given a 2D array of integers where each row and column are sorted in ascending order, write
// a function to efficiently search for a target value in the array. Print the # of comparisons
// required before finding a target value through row-based and column-based searches.


#include <iostream>

using namespace std;

int rowWiseBinarySearch(int arr[4][4], int target){
    int comparisons = 0;
    for (int i = 0; i < 4; i++)
    {
        int left = 0;
        int right = 3;
        while (left <= right)
        {
            comparisons++;
            int mid = (left + right) / 2;

            if (arr[i][mid] == target)
            {
                cout << target << " found at index " << mid <<"," << i << endl;
                return comparisons;
            }
            else if (arr[i][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int columnWiseBinarySearch(int arr[4][4], int target){
    int comparisons = 0;
    for (int i = 0; i < 4; i++)
    {
        int left = 0;
        int right = 3;
        while (left <= right)
        {
            comparisons++;
            int mid = (left + right) / 2;

            if (arr[mid][i] == target)
            {
                cout << target << " found at index " << mid <<"," << i << endl;
                return comparisons;
            }
            else if (arr[mid][i] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int twoDimensionalBinarySearch(int arr[4][4], int target)
{
    int comparisons = 0;
    int left = 0;
    int right = 15;
    while(left <= right)
    {
        comparisons++;
        int mid = (left + right) / 2;
        int row = mid / 4;
        int col = mid % 4;
        if(arr[row][col] == target)
        {
            cout << target << " found at index " << row << "," << col << endl;
            return comparisons;
        }
        else if(arr[row][col] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    int target = 11;

    cout<< "Row Based:" << rowWiseBinarySearch(arr, target) << endl;
    cout<< "Col Based:" << columnWiseBinarySearch(arr, target) << endl;
    cout<< "2D Binary Search" << twoDimensionalBinarySearch(arr, target)<<endl;

    return 0;
}

