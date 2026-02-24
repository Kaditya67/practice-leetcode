// Problem: https://leetcode.com/problems/leaf-similar-trees/
// Difficulty: Easy

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
    void leafSequence(TreeNode* root, vector<int>& res){
        if(!root) return;
        if(!root->left && !root->right){
            res.push_back(root->val);
            return;
        }
        leafSequence(root->left,res);       // Left -> right => Inorder traversal
        leafSequence(root->right,res);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1,res2; 

        leafSequence(root1,res1);
        leafSequence(root2,res2);

        if(res1.size()!= res2.size()) return false;

        for(int i=0;i<res1.size();i++){
            if(res1[i]!=res2[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->left->right->right = new TreeNode(9);
    root2->left->right->left = new TreeNode(8);

    cout << boolalpha << s.leafSimilar(root1, root2) << endl; // Expected output: true
    return 0;
}
