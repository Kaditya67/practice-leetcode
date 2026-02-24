// Problem: https://leetcode.com/problems/delete-node-in-a-bst/
// Difficulty: Medium

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* getMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }
public:
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) { 
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) { 
            root->right = deleteNode(root->right, key);
        } else { 
            if (!root->left && !root->right) {  // Case 1 : No child
                delete root;
                return nullptr;
            }
 
            if (!root->left) {                 // Case 2 : One child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
 
            // Case 3 : Two children
            TreeNode* successor = getMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);      // Recursively delete the successor -> If there are many nodes then it will taken care of in the same way
        }

        return root;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Original BST (Inorder): ";
    s.inorder(root);
    cout << endl;

    int key = 3;
    root = s.deleteNode(root, key);

    cout << "BST after deleting node " << key << " (Inorder): ";
    s.inorder(root);
    cout << endl;

    return 0;
}

