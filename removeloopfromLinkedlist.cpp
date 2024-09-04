#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void InputLinkedList(Node *head, int n)
{
    Node *temp = head;
    for (int i = 1; i < n; i++)
    { // Start from 1 since head is already created
        int val;
        cin >> val;
        Node *newNode = new Node(val);
        temp->next = newNode;
        temp = temp->next;
    }

    printList(head);
}

void reverseLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    printList(prev);
}

Node *reverseInGroups(Node *head, int k)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = reverseInGroups(next, k);
    }

    return prev;
}

Node *detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    cout << "slow : " << slow->data << " fast : " << fast->data << endl;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Cycle Detected at : " << slow->data << endl;
            break;
        }
        cout << "slow : " << slow->data << " fast : " << fast->data << endl;
    }

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{

    // Adding more nodes to the linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(20);

    // Adding more nodes
    head->next->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next->next = new Node(70);
    head->next->next->next->next->next->next->next->next = new Node(80);

    cout << "Original Linked List: " << endl;
    printList(head);

    // int n;
    // cout << "How many nodes do you want to add: ";
    // cin >> n;

    // if (n <= 0) {
    //     cout << "Invalid number of nodes." << endl;
    //     return 0;
    // }

    // int h;
    // cout << "Head Element: ";
    // cin >> h;

    // cout << "\nInput Elements:" << endl;

    // Node* head = new Node(h);
    // InputLinkedList(head, n);

    // reverseLinkedList(head);

    // int k;
    // cout << "\nInput k: ";
    // cin >> k;
    // cout << endl;

    // reverseInGroups(head, k);

    // Adding cycle
    head->next->next->next->next->next = head->next->next;

    Node *cycle = detectCycle(head);

    cout << "Cycle is at : " << cycle->data << endl;
    return 0;
}
