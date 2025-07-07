#include<bits/stdc++.h>
using namespace std;


void printArray(vector<int> &arr){
    for(int num:arr){
        cout<<num<<" ";
    }
    cout<<endl;
}

void Heapify(vector<int>&arr,int n,int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[largest] < arr[l]) largest = l;
    if(r<n && arr[largest] < arr[r]) largest = r;

    if(largest!=i){
        swap(arr[largest],arr[i]);
        Heapify(arr,n,largest);     // Heapify again on the smaller one to go deeper
    }
}

void heapSort(vector<int> &arr){
    // 1. Build Max Heap
    int n = arr.size();
    for(int i=n/2;i>=0;i--){
        Heapify(arr,n,i);
    }

    // 2. Put the root to end and reduce Heap Size and Heapify to maintain Max Heap
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);        // Move root to end
        Heapify(arr,i,0);       // Always call heapify on the root till one reduced length
    }
}

int main(){
    vector<int> arr = {3, 9, 2, 1, 4, 5};

    cout << "Original array: ";
    printArray(arr);

    heapSort(arr);

    cout << "Sorted array (Heap Sort): ";
    printArray(arr);

    return 0;
}