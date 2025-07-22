// Pass max value from root to leaves
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function prototypes
void dfs(TreeNode* node, int maxSoFar) {
    if (!node) return;

    maxSoFar = max(maxSoFar, node->val); // <-- update max on the path
    if (!node->left && !node->right) {
        cout << "Leaf: " << node->val << ", Max on path: " << maxSoFar << endl;
    }

    dfs(node->left, maxSoFar);  // <-- propagate down
    dfs(node->right, maxSoFar); // <-- propagate down
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    dfs(root, INT_MIN);

    return 0;
}

// Output:
// Leaf: 2, Max on path: 5
// Leaf: 4, Max on path: 5
// Leaf: 7, Max on path: 8
// Leaf: 9, Max on path: 8