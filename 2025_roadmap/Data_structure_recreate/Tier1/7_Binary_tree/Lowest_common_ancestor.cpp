#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* findLCA(Node* root, int p, int q) {
    if (!root) return nullptr;
    if (root->data == p || root->data == q) return root;    // If one of them is found

    Node* left = findLCA(root->left, p, q);     // Find in more depth if not found
    Node* right = findLCA(root->right, p, q);

    if (left && right) return root; // IF both are not null at any point for the root, return the 1st root for which they are not null
    return left ? left : right;
}

int main() {
    // Build the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Test
    Node* lca = findLCA(root, 4, 5);
    cout << "LCA(4,5) = " << (lca ? lca->data : -1) << endl;

    lca = findLCA(root, 4, 6);
    cout << "LCA(4,6) = " << (lca ? lca->data : -1) << endl;

    lca = findLCA(root, 3, 6);
    cout << "LCA(3,6) = " << (lca ? lca->data : -1) << endl;

    return 0;
}

//            1
//         /     \
//       2         3
//     /   \      /   \
//    4     5    6     7
//   / \         \
//  8   9         10

// findLCA(1, 9, 10)
// ├── findLCA(2, 9, 10)
// │   ├── findLCA(4, 9, 10)
// │   │   ├── findLCA(8, 9, 10) → NULL
// │   │   └── findLCA(9, 9, 10) → 9 ✅
// │   │       → one child returned non-null → return 9
// │   └── findLCA(5, 9, 10) → NULL
// │       → one child returned 9 → return 9
// ├── findLCA(3, 9, 10)
// │   ├── findLCA(6, 9, 10)
// │   │   ├── findLCA(NULL, 9, 10) → NULL
// │   │   └── findLCA(10, 9, 10) → 10 ✅
// │   │       → one child returned → return 10
// │   └── findLCA(7, 9, 10) → NULL
// │       → one child returned 10 → return 10
// → left returned 9, right returned 10 ⇒ return 1 ✅ (LCA)
