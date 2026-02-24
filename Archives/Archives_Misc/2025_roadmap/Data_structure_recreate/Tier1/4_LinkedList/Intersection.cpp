#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// 🔍 Detect intersection node by reference using hash set
Node* getIntersectionNode(Node* headA, Node* headB) {
    unordered_set<Node*> nodes_set;
    while (headA != nullptr) {
        nodes_set.insert(headA);
        headA = headA->next;
    }
    while (headB != nullptr) {
        if (nodes_set.find(headB) != nodes_set.end()) {
            return headB;
        }
        headB = headB->next;
    }
    return nullptr;
}


// If any pointer reaches the end (nullptr), redirect it to the other list’s head
// ptr1 = ptr1 ? ptr1->next : headB;
// ptr2 = ptr2 ? ptr2->next : headA;

// | Step | ptr1 | ptr2 |
// | ---- | ---- | ---- |
// | 1    | 1    | 9    |
// | 2    | 2    | 4    |
// | 3    | 3    | 5    |
// | 4    | 4    | NULL |
// | 5    | 5    | 1    |
// | 6    | NULL | 2    |
// | 7    | 9    | 3    |
// | 8    | 4    | 4 ✅  |


// Both travels same no. of steps
// ################# Floyd’s Intersection Detection Algorithm ####################
Node* findIntersection(Node* headA, Node* headB) {
    Node* ptr1 = headA;
    Node* ptr2 = headB;
    while (ptr1 != ptr2) {
        ptr1 = ptr1 ? ptr1->next : headB;   // Switch to next node
        ptr2 = ptr2 ? ptr2->next : headA;
    }
    return ptr1;    
}

// Other Case
// List A: 1 → 2 → 3 → 4  
// List B:     9 → 8


// | Step | `a` value | `b` value |
// | ---- | --------- | --------- |
// | 1    | 1         | 9         |
// | 2    | 2         | 8         |
// | 3    | 3         | nullptr   |
// | 4    | 4         | 1         |
// | 5    | nullptr   | 2         |
// | 6    | 9         | 3         |
// | 7    | 8         | 4         |
// | 8    | nullptr   | nullptr ✅ |



int main() {
    LinkedList list1;

    // Create List 1: 1 → 2 → 3 → 4 → 5
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);
    list1.insertAtEnd(5);

    // Store pointer to node 3
    Node* intersection = list1.head->next->next; // node with value 3

    // Manually create List 2: 6 → 7 → 3 → 4 → 5 (intersecting from 3)
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    n6->next = n7;
    n7->next = intersection;

    LinkedList list2;
    list2.head = n6;

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    Node* intersectNode = getIntersectionNode(list1.head, list2.head);
    if (intersectNode) {
        cout << "Intersection at node with value: " << intersectNode->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
