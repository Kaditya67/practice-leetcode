#include <iostream>
#include <vector>
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
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1->val <= l2->val) {
            l1->next = mergeTwoSortedList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedList(l1, l2->next);
            return l2;
        }
    }

    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if (start > end) {
            return nullptr;
        }
        if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode* L1 = partitionAndMerge(start, mid, lists);
        ListNode* L2 = partitionAndMerge(mid + 1, end, lists);

        return mergeTwoSortedList(L1, L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return nullptr;
        }
        return partitionAndMerge(0, k - 1, lists);
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

int main() {
    // Example input: 3 sorted linked lists
    vector<ListNode*> lists;
    lists.push_back(createLinkedList({1, 4, 5}));
    lists.push_back(createLinkedList({1, 3, 4}));
    lists.push_back(createLinkedList({2, 6}));

    Solution solution;
    ListNode* mergedHead = solution.mergeKLists(lists);

    // Output the merged linked list
    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}
    