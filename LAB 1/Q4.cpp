/* Implement Intersection of two arrays. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cout << "Enter the size of the first array: ";
    cin >> n;

    vector<int> arr1(n);
    cout << "Enter the elements of the first array: ";
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> m;

    vector<int> arr2(m);
    cout << "Enter the elements of the second array: ";
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> result;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(arr1[i] == arr2[j]){
            result.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    cout << "The intersection of the two arrays is: ";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}