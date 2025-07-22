// Problem: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    int findNodes(TreeNode *root, int prevMax){
        if(!root) return 0;

        int count = 0;
        if (root->val >= prevMax) {
            count = 1;
            prevMax = root->val;
        }

        count += findNodes(root->left, prevMax);
        count += findNodes(root->right, prevMax);

        return count;
    }
    int goodNodes(TreeNode* root) {
        return findNodes(root, root->val);
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4, new TreeNode(3), new TreeNode(1));
    root->left->left = new TreeNode(3);
    cout << s.goodNodes(root) << endl; // Expected output: 4
    return 0;
}
