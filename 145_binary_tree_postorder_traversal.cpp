#include<iostream>
#include<vector>    

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;

        if (root == nullptr) {
            return nodes;  // Return empty vector if root is null
        }

        postorderHelper(root, nodes);  // Call helper function to perform traversal
        return nodes;
    }

private:
    void postorderHelper(TreeNode* node, vector<int>& nodes) {
        if (node == nullptr) {
            return;
        }


        postorderHelper(node->left, nodes);   // Traverse left subtree
        postorderHelper(node->right, nodes);  // Traverse right subtree
        nodes.push_back(node->val);  // Visit the current node
    }
};

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);

    Solution s;

    vector<int> result = s.postorderTraversal(root);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}