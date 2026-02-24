#include <iostream>
#include <vector>
using namespace std;

void printHeap(const vector<int>& heap) {
    for (int val : heap) cout << val << " ";
    cout << endl;
}

void heapify(vector<int>& heap, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && heap[l] > heap[largest]) largest = l;
    if (r < n && heap[r] > heap[largest]) largest = r;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        cout << "Swapped " << heap[largest] << " with " << heap[i] << ": ";
        printHeap(heap);
        heapify(heap, n, largest);
    }
}

void buildMaxHeap(vector<int>& heap) {
    int n = heap.size();

    cout << "Original array: ";
    printHeap(heap);

    for (int i = n/2 - 1; i >= 0; i--) {
        cout << "Heapifying at index " << i << " (value: " << heap[i] << ")\n";
        heapify(heap, n, i);
    }

    cout << "Final Max Heap: ";
    printHeap(heap);
}

int main() {
    vector<int> arr = {3, 9, 2, 1, 4, 5};
    buildMaxHeap(arr);
    return 0;
}
