// Problem: https://leetcode.com/problems/reverse-linked-list/
// Difficulty: Easy
// concept: Two Pointers in linked list --> Very very helpful

#include <bits/stdc++.h>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next; 
            curr->next = prev;               
            prev = curr;                    
            curr = nextNode;                 
        }

        return prev;  
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    head = s.reverseList(head);

    // Print the modified linked list
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
