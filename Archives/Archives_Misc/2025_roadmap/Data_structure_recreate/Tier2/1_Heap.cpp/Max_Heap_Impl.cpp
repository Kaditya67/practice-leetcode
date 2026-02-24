#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
private:
    vector<int> heap;
    // 50,20,30,10,5, 15,10
    // 50 -> 0
    // 20 -> 1
    // 30 -> 2
    // 10 -> 3          // 2*i+1 = 2*1+1 = 3 
    // 5  -> 4          // 2*i+2 = 2*1+2 = 4

    // Return parent, left and right index
    int parent(int i){ return (i-1)/2;}     // for array i-1
    int leftChild(int i) { return 2*(i)+1; }
    int rightChild(int i) { return 2*i+2; }

    void heapifyUp(int i){
        while(i!=0 && heap[parent(i)]<heap[i]){
            swap(heap[parent(i)],heap[i]);
            i=parent(i);
        }
    }

    void heapifyDown(int i){
        int n = heap.size();
        int largest = i;        
        int l = leftChild(i), r = rightChild(i);

        if(l<n && heap[l]>heap[largest]) largest = l;       // if left child is greater
        if(r<n && heap[r]>heap[largest]) largest = r;       // if right is greater

        // if largest was updated then swap
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val){
        heap.push_back(val);
        heapifyUp(heap.size()-1);       // make this index go up if possible
    }

    void removeMax(){
        if(heap.empty()) return;
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void buildHeap(vector<int>&arr){
        heap = arr;
        int n = arr.size();
        for(int i=n/2-1;i>=0;i--){
            heapifyDown(i);
        }
    }

    void printHeap(){
        for(int val:heap) cout<<val<<" ";
        cout<<endl;
    }
    int getMax(){
        if(heap.empty()) return -1;
        return heap[0];
    }
};

int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(3);

    cout << "Heap after insertions: ";
    h.printHeap();

    cout << "Maximum: " << h.getMax() << endl;

    h.removeMax();
    cout << "Heap after removing max: ";
    h.printHeap();

    vector<int> arr = {9, 4, 7, 1, -2, 6, 5};
    h.buildHeap(arr);
    cout << "Heap built from array: ";
    h.printHeap();

    return 0;
}