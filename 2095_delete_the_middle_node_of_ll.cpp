#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr; // List is empty or has only one node
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        if (prev != nullptr) {
            prev->next = slow->next;
        }

        delete slow; // Free the memory of the middle node
        return head;
    }
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution solution;
    
    // Creating a test list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> nullptr
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 2; i <= 10; i++) {
        current->next = new ListNode(i);
        current = current->next;
    }
    
    cout << "Original list: ";
    printList(head);
    
    ListNode* updatedHead = solution.deleteMiddle(head);
    
    cout << "Updated list after deleting middle node: ";
    printList(updatedHead);
    
    // Cleanup memory (not necessary for this simple test, but good practice)
    while (updatedHead != nullptr) {
        ListNode* temp = updatedHead;
        updatedHead = updatedHead->next;
        delete temp;
    }
    
    return 0;
}
