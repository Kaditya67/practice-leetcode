#include<bits/stdc++.h>
using namespace std;

// FIFO = First In First Out 
class Stack{
private:
    int* arr;
    int capacity;
    int topIndex;
public:
    Stack(int capacity){
        this->capacity = capacity;
        arr  = new int[capacity];
        topIndex = -1;
    }

    ~Stack(){
        delete[] arr;
    }

    bool isFull(){
        return topIndex==capacity-1;
    }

    bool isEmpty(){
        return topIndex==-1;
    }

    void push(int val){
        if(isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = val;
    }

    void pop(){
        if(isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    int top(){
        if(isEmpty()) return -1;
        return arr[topIndex];
    }

    void display(){
        if(isEmpty()){
            cout<< "Stack is Empty\n";
            return;
        }

        for(int i=topIndex;i>=0;i--){
            cout<< arr[i]<<endl;
        }
        cout<< "Stack\n";
    }
};

//  using LL
struct Node{
    int data;
    Node* next;
    // Node(int val){
    //     data = val;
    //     next=nullptr;
    // }

    // constructor initializer list  --> better --> No creation and then assignment --> Direc5t Assign
    Node(int val): data(val),next(nullptr) {}
};

class StackLL{

private:
    Node* head;
public:
    StackLL() : head(nullptr) {}

    bool isEmpty(){
        return head==nullptr;
    }
    void push(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop(){
        if(isEmpty()){
            cout<< "Stack Underflow\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top(){
        if(isEmpty()){
            cout<<"Stack is Empty !\n";
            return -1;
        }
        return head->data;
    }

    void display(){
        if(isEmpty()){
            cout<<"Stack is Empty !\n";
            return;
        }

        Node* curr = head;
        while(curr){
            cout<<curr->data<<endl;
            curr = curr->next;
        }
        cout<<"Stack"<<endl;
    }

    ~StackLL(){
        while(!isEmpty()) pop();
    }
};

// // Normal Stack - Array
// int main() {
//     Stack s(5); // Stack with capacity 5
//     s.push(100);
//     s.push(200);
//     s.push(300);
//     s.display(); // Stack: 300 200 100

//     cout<<endl;
//     cout << "Top element: " << s.top() << endl; // Top element: 300

//     cout<< "Pop element "<<endl;
//     s.pop();

//     cout<<"\nDisplay Again : "<<endl;
//     s.display(); // Stack: 200 100

//     return 0;
// }

//! LinkedList Stack
int main() {
    StackLL s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    // Display current stack
    cout << "Initial Stack:\n";
    s.display(); // 30, 20, 10

    // Show top element
    cout << "\nTop element: " << s.top() << endl; // 30

    // Pop one element
    cout << "Popping one element...\n";
    s.pop();

    // Display updated stack
    cout << "After popping:\n";
    s.display(); // 20, 10
    
    // Check if empty
    cout << "\nIs stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    cout<< "\nPopping twice ..." <<endl;
    s.pop();
    s.pop();
    cout << "\nIs stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    cout<<"\nPopping once Again..."<<endl;
    // Try popping from empty stack
    s.pop(); // Underflow

    return 0;
}
