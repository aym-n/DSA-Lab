/*Implement left shift with given number of steps*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter the number of steps: ";
    cin >> k;

    for(int i = k; i > 0; i--){
        for(int j = 0; j < n - 1; j++){
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = 0;
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}