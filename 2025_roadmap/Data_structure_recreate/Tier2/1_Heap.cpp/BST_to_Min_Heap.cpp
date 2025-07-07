#include<bits/stdc++.h>
using namespace std;

// Original BST:
//         4
//       /   \
//      2     6
//     / \   / \
//    1  3  5   7

// Min Heap
//         1
//       /   \
//      2     3
//     / \   / \
//    4  5  6  7

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Step 1: Inorder → sorted values
void inorder(Node* root, vector<int>& vals) {
    if (!root) return;
    inorder(root->left, vals);
    vals.push_back(root->data);     // Get the sorted sequence
    inorder(root->right, vals);
}

// Step 2: Replace values in preorder (min heap filling)
void fillPreorder(Node* root, vector<int>& vals, int& idx) {
    if (!root) return;
    root->data = vals[idx++];       // Fill Sorted Values in the place
    fillPreorder(root->left, vals, idx);
    fillPreorder(root->right, vals, idx);
}

void convertBSTToMinHeap(Node* root) {
    vector<int> sorted;
    inorder(root, sorted);
    int index = 0;
    fillPreorder(root, sorted, index);
}

// Helper to print level order
void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->data << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << endl;
}

int main() {
    // BST
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << "Original BST (Level Order): ";
    printLevelOrder(root);

    convertBSTToMinHeap(root);

    cout << "Min Heap (Same Tree Structure): ";
    printLevelOrder(root);

    return 0;
}