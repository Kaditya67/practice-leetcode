#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i)   { return (i - 1) / 2; }
    int left(int i)     { return 2 * i + 1; }
    int right(int i)    { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        int smallest = i;
        int l = left(i), r = right(i);

        if (l < n && heap[l] < heap[smallest]) smallest = l;
        if (r < n && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    void removeMin() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void buildHeap(vector<int>& arr) {
        heap = arr;
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(3);

    cout << "Heap after insertions: ";
    h.printHeap();

    cout << "Minimum: " << h.getMin() << endl;

    h.removeMin();
    cout << "Heap after removing min: ";
    h.printHeap();

    vector<int> arr = {9, 4, 7, 1, -2, 6, 5};
    h.buildHeap(arr);
    cout << "Heap built from array: ";
    h.printHeap();

    return 0;
}
