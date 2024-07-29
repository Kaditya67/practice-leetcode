#include <iostream>
#include<vector>
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // Check if the list is empty or has only one element
        
        ListNode* odd = head;              // Initialize the odd pointer
        ListNode* even = head->next;       // Initialize the even pointer
        ListNode* evenStart = even;        // Store the start of the even list

        while (even && even->next) {       // Traverse the list
            odd->next = even->next;        // Link odd nodes
            odd = odd->next;               // Move odd pointer
            even->next = odd->next;        // Link even nodes
            even = even->next;             // Move even pointer
        }

        odd->next = evenStart;             // Append even list to the end of the odd list
        return head;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;

    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a linked list [1, 2, 3, 4, 5]
    std::vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(nums);

    std::cout << "Original linked list: ";
    printLinkedList(head);

    Solution solution;
    ListNode* rearrangedHead = solution.oddEvenList(head);

    std::cout << "Odd-even rearranged linked list: ";
    printLinkedList(rearrangedHead);

    return 0;
}
