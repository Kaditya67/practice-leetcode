#include<bits/stdc++.h>
using namespace std;

// A heap is a complete binary tree → stored as array.
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void convertToMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n/2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> minHeap = {1, 3, 5, 7, 9, 11};  // Min Heap
    cout << "Original Min Heap: ";
    printArray(minHeap);

    convertToMaxHeap(minHeap);

    cout << "Converted Max Heap: ";
    printArray(minHeap);

    return 0;
}
