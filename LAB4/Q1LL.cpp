// Implement the Merge Sort algorithm as a function that takes an List of integers and sorts it.

#include<iostream>
#include<climits>
#include<list>

using namespace std;

void merge(list<int> &arr, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    list<int> L, R;

    for(int i = 0; i < n1; i++){
        L.push_back(arr.front());
        arr.pop_front();
    }
    for(int j = 0; j < n2; j++){
        R.push_back(arr.front());
        arr.pop_front();
    }

    L.push_back(INT_MAX);
    R.push_back(INT_MAX);

    int i = 0, j = 0;
    for(int k = p; k <= r; k++){
        if(L.front() <= R.front()){
            arr.push_back(L.front());
            L.pop_front();
        }else{
            arr.push_back(R.front());
            R.pop_front();
        }
    }
}

void mergeSort(list<int> &arr, int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main(){
    list<int> arr = {5, 2, 4, 7, 1, 3, 2, 6};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    for(auto i = arr.begin(); i != arr.end(); i++){
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}

