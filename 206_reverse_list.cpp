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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        
        while (current != nullptr) {
            ListNode* next = current->next; // Save the next node
            current->next = prev;           // Reverse the current node's pointer
            prev = current;                 // Move prev and current one step forward
            current = next;
        }
        
        return prev; // Prev will be the new head of the reversed list
    }
};


// // Dry Run
// nextPointer=address to next linkedlist node (2)
// set current->next=prev;     // store the previous node address in current to revser the node
// set prev=current;           // store the address of current node for giving to next node
// set current=next;           // use the next to move to next node

// 1. Store the address of next ListNode in nextPointer(temp storage)
// 2. change the pointing address of node to previous
// 3. store the address of current node in prev using current
// 4. Move to the next node using current




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
    
    // Creating a test list: 1 -> 2 -> 3 -> 4 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    cout << "Original list: ";
    printList(head);
    
    ListNode* reversedHead = solution.reverseList(head);
    
    cout << "Reversed list: ";
    printList(reversedHead);
    
    // Cleanup memory (not necessary for this simple test, but good practice)
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }
    
    return 0;
}
