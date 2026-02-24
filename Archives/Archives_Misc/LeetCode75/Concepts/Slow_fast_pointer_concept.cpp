/**
 * The slow and fast pointer concept is an algorithmic concept that uses two pointers, one moving at twice the speed of the other, to traverse a data structure and detect a cycle or find the middle element.
 *
 * The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. If there is a cycle in the data structure, the two pointers will eventually meet at some point. If there is no cycle, the fast pointer will reach the end of the data structure.
 *
 * Floyd's Cycle Detection Algorithm is an example of the slow and fast pointer concept, which is used to detect a cycle in a linked list.
 */

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        cout << "List is too short, no cycle possible." << endl;
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        cout << "Slow pointer at: " << slow->val << ", Fast pointer at: ";
        if(fast) cout << fast->val << endl;
        else cout << "nullptr" << endl;

        if (slow == fast) {
            cout << "Cycle detected at node: " << slow->val << endl;
            return true;
        }
    }
    cout << "No cycle detected in the list." << endl;
    return false;
}

int main() {
    // Creating a linked list with a cycle for demonstration
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Creates a cycle

    hasCycle(head);

    return 0;
}

