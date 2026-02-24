#include <bits/stdc++.h>
using namespace std;

// ------------------------- Node Structure -------------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// ------------------------- Tree Builder -------------------------
/*
            10
           /  \
         2     10
        / \      \
       20  1      -25
                   /  \
                  3    4
*/

void mirrorTree(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        // Swap children
        swap(curr->left, curr->right);

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

// mirrorTree(1)
// ├── swap(2, 3)
// ├── mirrorTree(3)
// │   └── swap(NULL, NULL)
// │   ├── mirrorTree(NULL) → return
// │   └── mirrorTree(NULL) → return
// └── mirrorTree(2)
//     └── swap(4, 5)
//     ├── mirrorTree(5)
//     │   └── swap(NULL, NULL)
//     │   ├── mirrorTree(NULL) → return
//     │   └── mirrorTree(NULL) → return
//     └── mirrorTree(4)
//         └── swap(NULL, NULL)
//         ├── mirrorTree(NULL) → return
//         └── mirrorTree(NULL) → return


int main() {
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    return 0;
}
