// 3 -> 2 -> 0 -> 4                   cycle  4 -> 2
// s=2     f=0
// s=0     f=2
// s=4     f=4
//! Meet  --> There is cycle

// 3 -> 2 -> 0 -> 4 -> 7 -> 6                  cycle  6 -> 0
// s=2     f=0
// s=0     f=4
// s=4     f=6
// s=7     f=4
// s=6     f=6
//! Meet --> There is cycle

#include <iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to create a cycle in the linked list for testing
ListNode* createCycleLinkedList(const std::vector<int>& nums, int pos) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    ListNode* cycleEntry = nullptr;

    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
        if (i == pos) {
            cycleEntry = current;
        }
    }

    if (cycleEntry != nullptr) {
        current->next = cycleEntry;  // Create the cycle
    }

    return head;
}

// Function to print the linked list (for testing without cycle)
void printLinkedList(ListNode* head, int limit = 10) {
    ListNode* current = head;
    int count = 0;
    while (current != nullptr && count < limit) {
        std::cout << current->val << " ";
        current = current->next;
        count++;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head; 
        ListNode* fast = head; 

        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           
            fast = fast->next->next;     

            if (slow == fast) {          
                break;
            }
        }

        if (fast != slow) {
            return NULL;                 
        }

        ListNode* pos = head;           
        while (pos != slow) {
            pos = pos->next;             
            slow = slow->next;
        }
        
        return pos;                      
    }
};

int main() {
    // Example: Creating a list with a cycle
    std::vector<int> nums = {3, 2, 0, -4};
    int cyclePos = 1; // Position where the cycle starts (index 1 means the second node)

    ListNode* head = createCycleLinkedList(nums, cyclePos);

    Solution solution;
    ListNode* cycleEntry = solution.detectCycle(head);

    if (cycleEntry) {
        std::cout << "Cycle detected at node with value: " << cycleEntry->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    return 0;
}
