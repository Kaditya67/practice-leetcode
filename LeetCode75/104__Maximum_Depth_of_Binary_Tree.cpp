// Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Difficulty: Easy

#include <bits/stdc++.h>
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
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = maxDepth(root->left);   // Go deepest in left
        int rightDepth = maxDepth(root->right); // Go deepest in right
        return max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    cout << s.maxDepth(root) << endl; // Expected output: 3
    return 0;
}

