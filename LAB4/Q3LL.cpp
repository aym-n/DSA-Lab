// Implement the Quick Sort algorithm as a function that takes an List of integers and sorts it.

#include<iostream>
#include<list>

using namespace std;

int partition(list<int> &arr, int p, int r){
    auto temp = arr.begin();
    advance(temp, r);
    int x = *temp;
    int i = p - 1;
    for(int j = p; j < r; j++){
        auto temp1 = arr.begin();
        advance(temp1, j);
        if(*temp1 <= x){
            i++;
            auto temp2 = arr.begin();
            advance(temp2, i);
            swap(*temp1, *temp2);
        }
    }
    auto temp3 = arr.begin();
    advance(temp3, i + 1);
    swap(*temp, *temp3);
    return i + 1;
}

void quickSort(list<int> &arr, int p, int r){
    if(p < r){
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main(){
    list<int> arr = {5, 2, 4, 7, 1, 3, 2, 6};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    for(auto i = arr.begin(); i != arr.end(); i++){
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}