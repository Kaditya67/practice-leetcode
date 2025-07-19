// # Algorithm:
// 1. Pick a pivot (here: mid element), move it to the end.
// 2. Use a pointer 'pos' to track correct location of ≤ pivot values.
// 3. For every element ≤ pivot, increment 'pos' and swap.
// 4. After loop, place pivot at pos+1.
// 5. Recur on [low, pivotIndex-1] and [pivotIndex+1, high]

#include<bits/stdc++.h>
using namespace std;

int partitionArray(vector<int> &arr, int low, int high){
    int pos=low-1;    // Keep this one element back, till it is sorted
    int mid = low+(high-low)/2;
    swap(arr[mid],arr[high]);       // Keep the pivot at the end

    int pivot = arr[high];
    for(int i=low;i<high;i++){
        if(arr[i]<=pivot){
            pos++;        // Increment to get the correct position
            swap(arr[pos],arr[i]);
        }
    }
    swap(arr[pos+1],arr[high]);     // Now Keep the pivot on correct place
    return pos+1;       // Here is the pivot
}

void quickSort(vector<int> &arr, int low,  int high){
    if(low>=high) return;

    int pivotIndex = partitionArray(arr, low,high);

    // Call the recursion of remaining parts not on pivotIndex
    quickSort(arr, low, pivotIndex-1);
    quickSort(arr, pivotIndex+1, high);
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original Array:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}