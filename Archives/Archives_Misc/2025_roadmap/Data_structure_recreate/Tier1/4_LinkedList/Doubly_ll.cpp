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

// head → [1] ← tail

// head
//  ↓
// [2] ⇄ [1] ← tail

// head
//  ↓
// [2] ⇄ [1] ⇄ [3] ⇄ [4]
//                    ↑
//                   tail


class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;       // Old 1st Node -> prev is NewNode
            head = newNode;     // Head points to NewNode
        }
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteByValue(int val) {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        // If deleting head
        if (temp->prev == nullptr) {
            head = temp->next;  // Set to 2nd Node
            if (head != nullptr) head->prev = nullptr;  // 2nd Node-> prev is now Nullptr as
            else tail = nullptr;  // list becomes empty
        }

        // If deleting tail
        else if (temp->next == nullptr) {
            tail = temp->prev;
            tail->next = nullptr;
        }

        // Middle node
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(1);
    dll.insertAtHead(2);
    dll.insertAtTail(3);
    dll.insertAtTail(4);
    dll.display();
    dll.deleteByValue(3);
    dll.display();
    return 0;
}
