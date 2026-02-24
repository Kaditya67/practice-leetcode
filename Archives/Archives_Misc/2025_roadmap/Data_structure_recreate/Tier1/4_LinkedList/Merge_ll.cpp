#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }

    void setHead(Node* newHead) {
        head = newHead;

        // Recalculate tail
        tail = newHead;
        while (tail && tail->next) {
            tail = tail->next;
        }
    }
};

Node* mergeList(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Choose initial head
    if (h1->data < h2->data) {
        head = tail = h1;
        h1 = h1->next;
    } else {
        head = tail = h2;
        h2 = h2->next;
    }
    tail->next = nullptr;
    tail->prev = nullptr;

    // Merge remaining nodes
    while (h1 && h2) {
        if (h1->data < h2->data) {
            tail->next = h1;
            h1->prev = tail;
            tail = h1;
            h1 = h1->next;
        } else {
            tail->next = h2;
            h2->prev = tail;
            tail = h2;
            h2 = h2->next;
        }
    }

    // Attach remaining nodes
    while (h1) {
        tail->next = h1;
        h1->prev = tail;
        tail = h1;
        h1 = h1->next;
    }

    while (h2) {
        tail->next = h2;
        h2->prev = tail;
        tail = h2;
        h2 = h2->next;
    }
    tail->next = nullptr;
    return head;
}


// 🔧 Driver
int main() {
    DoublyLinkedList list1, list2;

    list1.insertAtTail(1);
    list1.insertAtTail(3);
    list1.insertAtTail(5);

    list2.insertAtTail(2);
    list2.insertAtTail(4);
    list2.insertAtTail(6);

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    Node* mergedHead = mergeList(list1.getHead(), list2.getHead());

    DoublyLinkedList mergedList;
    mergedList.setHead(mergedHead);

    cout << "Merged: ";
    mergedList.display();

    return 0;
}
