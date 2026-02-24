// Problem: https://leetcode.com/problems/path-sum-iii/
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

// Runtime: Runtime 15ms | Beats 28.65% --> Recursion solution
class Solution {
public:
    // This reminds me of Take/Not Take Method learnt in recursion
    int countFromNode(TreeNode *root, long long currSum, int targetSum){
        if(!root) return 0;

        int count = 0;
        currSum += root->val;
        if (currSum == targetSum) count++;  // Maqsad

        count += countFromNode(root->left, currSum, targetSum);
        count += countFromNode(root->right, currSum, targetSum);
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return countFromNode(root, 0, targetSum) + pathSum(root->left, targetSum)
        + pathSum(root->right, targetSum);
    }
    
};


// Better Solution: Backtracking + Prefix Sum + Hashmap
// Runtime 2ms | Beats 92.22%
class Solution2 {
public:
    int dfs(TreeNode* root, long long currSum, int targetSum, unordered_map<long long, int>& prefixSumCount) {
        if (!root) return 0;

        currSum += root->val;
        int count = 0;

        if (prefixSumCount.find(currSum - targetSum) != prefixSumCount.end()) {
            count += prefixSumCount[currSum - targetSum];   // We are using the difference
        }

        prefixSumCount[currSum]++;

        // Take
        count += dfs(root->left, currSum, targetSum, prefixSumCount);
        count += dfs(root->right, currSum, targetSum, prefixSumCount);

        // Backtrack: remove current prefix sum from the map
        prefixSumCount[currSum]--;      // Not Take

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1; // Base case: one way to reach sum = 0   
        return dfs(root, 0, targetSum, prefixSumCount);
    }
};


int main() {
    Solution s;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    cout << s.pathSum(root, 8) << endl;
    return 0;
}
