// # Algorithm
// 1. Use (max-heap) heapify to find the Largest Element on Top --> Store here
// Heapify => 
    // root = i
    // left_child = 2*i
    // right_child = 2*i+1
    // Just Pick the element compare with the children and Swap if better found 
    // Heapify recrusively for the change until no change found
// 2. Pick the top Node, Place at the end by using Swap and heapify the rest of the Tree

#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void heapify(vector<int>&arr, int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[largest]) largest = l;
    if(r<n && arr[r]>arr[largest]) largest = r; // Right always later

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(vector<int> &arr){
    int n = arr.size();

    // Store in heap -> A heap has n/2 childrens
    // Leaf nodes are the nodes that have no children → they don't need heapify
    // So we start from the last non-leaf node, which is at index n/2 - 1   // 1st index for the leaf node
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);       // Call heapify from the leaf node
    }

    // Pick the root node and place at the end and Heapify the rest
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);   // heapify the Top now
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