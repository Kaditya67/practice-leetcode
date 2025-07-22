// Problem: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int maxLen=0;
    void dfs(TreeNode* node, bool isLeft, int length) {
        if (!node) return;
        maxLen = max(maxLen, length);

        if (isLeft) {
            dfs(node->right, false, length + 1);  // left → right
            dfs(node->left, true, 1);   // Restart
        }else{
            dfs(node->left, true, length + 1);  // right → left
            dfs(node->right, false, 1); // Restart
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root->left, true, 1);   
        dfs(root->right, false, 1);
        return maxLen;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(1);
    cout << s.longestZigZag(root) << endl; // 3
    return 0;
}
