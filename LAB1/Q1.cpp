/*
Find the 'nth' largest and smallest element in an array.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    sort(arr.begin(), arr.end());
    cout << "The " << k << "th largest element is: " << arr[n - k] << endl;
    cout << "The " << k << "th smallest element is: " << arr[k - 1] << endl;
    return 0;
}