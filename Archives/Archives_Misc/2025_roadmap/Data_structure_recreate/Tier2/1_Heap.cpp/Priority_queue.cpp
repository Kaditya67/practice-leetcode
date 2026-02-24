#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void demoMaxHeap() {
    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);
    maxHeap.push(1);

    cout << "🔺 Max Heap (default priority_queue): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
}

void demoMinHeap() {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);
    minHeap.push(1);

    cout << "🔻 Min Heap (priority_queue with greater<int>): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {
    demoMaxHeap();
    demoMinHeap();
    return 0;
}
