// # Algorithm
// 1. Pick the Middle Point
// 2. Break into two part -> low, mid and mid+1,high        // Recursively move down
// 3. Merge the Parts // In sorted order

#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>&arr,int low, int mid, int high){
    int n1 = mid-low+1;     // Low is 0 for 1st part
    int n2 = high - mid;        // Difference is correct

    // Create Temporary arr & Copy
    vector<int> L(n1),R(n2);
    for(int i=0;i<n1;i++) L[i]=arr[low+i];
    for(int i=0;i<n2;i++) R[i]=arr[mid+1+i];

    int i=0,j=0,k = low;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }

    // Remaining elements
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];

}
void mergeSort(vector<int> &arr, int low, int high){
    if(low>=high){
        return;
    }
    int mid = low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    Merge(arr,low,mid,high);
}

int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original Array:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}