// Problem: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Difficulty: Medium

// Get Excited --> We are learning NEW CONCEPTS !
// Slow and Fast Pointer Concept -> Floyd's Cycle Detection Algorithm

// Brief
// Given the head of a singly linked list, delete the middle node and return the head of the modified linked list.
// Concept code present in /concept directory

#include<bits/stdc++.h>
using namespace std;

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
        if(!head || !head->next) return nullptr;    // Atleast Two Nodes

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Skip the middle Node
        prev->next = slow->next;
        return head;

    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Delete the middle node
    head = s.deleteMiddle(head);

    // Print the modified linked list
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}

