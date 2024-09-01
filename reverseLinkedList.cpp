#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(NULL) {}
};

// Function to reverse the linked list recursively
Node* reverseLinkedList(Node* head) {
    // Base case: If head is NULL or there's only one node, return the head
    if (head == NULL || head->next == NULL) {
        cout << "Base case reached: returning node with data " << (head ? head->data : -1) << endl;
        return head;
    }

    cout << "Recursively calling with head = " << head->data << endl;

    // Recursive case: Reverse the rest of the list
    Node* newHead = reverseLinkedList(head->next);

    cout << "Reversing links: " << head->next->data << " -> " << head->data << endl;

    // Adjust the pointers
    head->next->next = head;
    head->next = NULL;

    // Return the new head of the reversed list
    return newHead;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating a linked list 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    cout << "\nStarting to reverse the linked list...\n" << endl;
    head = reverseLinkedList(head);

    cout << "\nReversed Linked List: ";
    printList(head);

    return 0;
}
