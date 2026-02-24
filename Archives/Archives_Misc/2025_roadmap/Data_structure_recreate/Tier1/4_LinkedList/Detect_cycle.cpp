#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Floyd's Cycle Detection Algorithm (Tortoise & Hare)
bool hasCycle(Node* head) {
    if (!head || !head->next) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;          // 1 step
        fast = fast->next->next;    // 2 steps

        if (slow == fast) return true; // cycle detected
    }

    return false;
}

int main() {
    Node* head = new Node{1};
    head->next = new Node{2};
    head->next->next = new Node{3};
    head->next->next->next = head;

    cout << boolalpha << hasCycle(head) << endl;

    return 0;
}
