#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;

        if (root == nullptr) {
            return nodes;  // Return empty vector if root is null
        }

        preorderHelper(root, nodes);  // Call helper function to perform traversal
        return nodes;
    }

private:
    void preorderHelper(TreeNode* node, vector<int>& nodes) {
        if (node == nullptr) {
            return;
        }

        nodes.push_back(node->val);  // Visit the current node

        preorderHelper(node->left, nodes);   // Traverse left subtree
        preorderHelper(node->right, nodes);  // Traverse right subtree
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    vector<int> result = s.preorderTraversal(root);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;    // Output: 1 2 4 5 3

    return 0;
}