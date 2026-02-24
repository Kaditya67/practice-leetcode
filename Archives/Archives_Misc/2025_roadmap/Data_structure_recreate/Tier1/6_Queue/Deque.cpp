#include<bits/stdc++.h>
using namespace std;

class Deque{

private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    Deque(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~Deque() {
        delete[] arr;
        cout << "Deque memory released.\n";
    }

    bool isEmpty(){
        return rear==-1;
    }

    bool isFull(){
        return (front == (rear+1)%capacity);
    }

    void pushFront(int val){
        if(isFull()){
            cout << "Deque Overflow!\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }else{
            front = (front-1+capacity)%capacity;
        }
        arr[front] = val;
    }

    void pushBack(int val){
        if(isFull()){
            cout << "Deque Overflow!\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }else{
            rear = (rear+1)%capacity;
        }
        arr[rear] = val;
    }

    void popFront(){
        if (isEmpty()) {
            cout << "Deque Underflow!\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        }else {
            front = (front + 1) % capacity;
        }
    }

    void popBack(){
        if (isEmpty()) {
            cout << "Deque Underflow!\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        }else{
            rear = (rear-1+capacity)%capacity;
        }
    }

    int getFront(){
        return isEmpty() ? -1 : arr[front];
    }

    int getBack(){
        return isEmpty() ? -1 : arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deque: ";
        for (int i = front; ; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
            if (i == rear) break;
        }
        cout << endl;
    }


};

int main() {
    Deque dq(5);  // capacity 5

    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.display();  // Output: Deque: 5 10 20

    dq.popBack();
    dq.display();  // Output: Deque: 5 10

    dq.pushBack(30);
    dq.pushFront(2);
    dq.display();  // Output: Deque: 2 5 10 30

    dq.popFront();
    dq.display();  // Output: Deque: 5 10 30

    cout << "Front: " << dq.getFront() << ", Back: " << dq.getBack() << endl;

    return 0;
}
