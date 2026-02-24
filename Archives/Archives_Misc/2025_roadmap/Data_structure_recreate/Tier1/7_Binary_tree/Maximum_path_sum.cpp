#include <bits/stdc++.h>
using namespace std;

// ------------------------- Node Structure -------------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


//                           maxPathSumUtil(10)
//                           /               \
//              maxPathSumUtil(2)         maxPathSumUtil(10)
//               /           \                    \
//   maxPathSumUtil(20)   maxPathSumUtil(1)   maxPathSumUtil(-25)
//                                             /              \
//                                maxPathSumUtil(3)      maxPathSumUtil(4)


// Find the maximum sum path from one node to another node
// ------------------------- Max Path Sum Utility -------------------------
int maxPathSumUtil(Node* root, int& maxSum) {
    if (!root) return 0;

    // Get max path sum from left and right (ignore negatives)
    int left = max(0, maxPathSumUtil(root->left, maxSum));
    int right = max(0, maxPathSumUtil(root->right, maxSum));

    // Possible max path passing through this node (including both subtrees)
    maxSum = max(maxSum, root->data + left + right);

    // Return max gain including this node and one of its subtrees
    return root->data + max(left, right);
}

int maxPathSum(Node* root) {
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    return maxSum;
}

// ------------------------- Tree Builder -------------------------
/*
            10
           /  \
         2     10
        / \      \
       20  1      -25
                   /  \
                  3    4

   Max Path Sum = 20 + 2 + 10 + 10 = 42
*/

int main() {
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << "Maximum Path Sum = " << maxPathSum(root) << endl;

    return 0;
}
