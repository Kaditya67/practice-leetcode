#include<bits/stdc++.h>

using namespace std;

// LIFO = Last In First Out
class Queue{
private:
    int *arr;
    int firstIdx;
    int lastIdx;
    int capacity;
public:

    Queue(int size){
        arr = new int[size];        // Dynamic memory allocation
        firstIdx = 0, lastIdx = 0;
        capacity = size-1;
    }

    ~Queue(){
        delete[] arr;
        cout << "Queue memory released.\n"; // Dynamic memory freed
    }

    bool isEmpty(){
        return lastIdx==firstIdx;
    }

    int size(){
        return lastIdx - firstIdx;
    }

    int front(){
        return isEmpty()? -1: arr[firstIdx];
    }

    void enqueue(int val){
        if(lastIdx==capacity){
            cout<<"Queue Overflow!"<<endl;
            return;
        }
        arr[lastIdx++] = val;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            return;
        }
        firstIdx++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout<< "Queue :  ";
        for (int i = firstIdx; i < lastIdx; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};



int main() {
    Queue q(5); // queue with capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();   // Output: 10 20 30

    q.dequeue();   // removes 10
    q.display();   // Output: 20 30

    cout << "Front element: " << q.front() << endl; // 20
    cout << "Size: " << q.size() << endl;           // 2

    return 0;
}