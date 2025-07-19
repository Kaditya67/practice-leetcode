// # Algorithm: Counting Sort
// 1. Find the largest element
// 2. Count the frequency of each element
// 3. Store the elements in the sorted order in the array
// Works for array size <= 10^5

#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr){
    int n = arr.size();
    int k = *max_element(arr.begin(), arr.end());   // Get the max element
    vector<int> count(k+1,0);   // Count the frequency of each element

    for(int num:arr){
        count[num]++;
    }

    int idx = 0;
    for(int i=0;i<k+1;i++){
        while(count[i]--){
            arr[idx++] = i;
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main(){
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    printArray(arr);

    countingSort(arr);

    cout << "Sorted array (Counting Sort): ";
    printArray(arr);

    return 0;
}