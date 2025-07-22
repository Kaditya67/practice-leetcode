// Problem: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
// Difficulty: Medium
// concept: Linked List --> Using the previously solved problems as it is. Problem number : 206__Reverse_Linked_List and concept of Slow and Fast Pointer(Floyd's Cycle Detection Algorithm)

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

    int pairSum(ListNode* head) { 
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){ 
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;   // Disconnect 1st half
        prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* nextNode = curr->next; 
            curr->next = prev;               
            prev = curr;                    
            curr = nextNode;                 
        }

        // prev has reverse head
        int maxSum=INT_MIN;
        ListNode* temp1 = head;
        ListNode* temp2 = prev;
        while(temp1){
            int temp = (temp1->val + temp2->val);
            maxSum = max(maxSum, temp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return maxSum;

    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << s.pairSum(head) << endl;
    return 0;
}
