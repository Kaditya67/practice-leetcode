#include <iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//! This is solution  ####################################
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;  
        ListNode* fast = head;  
        
        while (fast != nullptr && fast->next != nullptr) {
            cout<<"Fast Value : "<<fast->val<<endl;
            fast = fast->next->next;  
            cout<<"Fast Value : "<<fast->val<<endl;
            slow = slow->next;         
        }
        
        return slow;  
    }
};

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

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    
    std::vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(nums);

    std::cout << "Original linked list: ";
    printLinkedList(head);

    Solution solution;
    ListNode* middle = solution.middleNode(head);

    std::cout << "Middle node value: " << middle->val << std::endl;

    return 0;
}
