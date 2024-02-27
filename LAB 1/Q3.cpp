/* Implement cyclic right rotate with given number of steps. */

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

    k = k % n;
    for(int i = 0; i < k; i++){
        int temp = arr[n - 1];
        for(int j = n - 1; j > 0; j--){
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }


    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
