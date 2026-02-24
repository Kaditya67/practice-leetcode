#include <iostream>
#include <algorithm>
using namespace std;

// Concept: Bubble up is a process of swapping elements in an array until a certain condition is satisfied.
// Code:
template<typename T>
void bubbleUp(T arr[], int n) {
    bool swapped;
    for (int i = 0; i < n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Explanation: Bubble up is a simple sorting algorithm which works by repeatedly swapping adjacent elements if they are in wrong order. It starts from the first element and compares it with the next element. If the first element is greater than the next element, it swaps them. This process is repeated until the end of the array is reached. The algorithm is then repeated until no more swaps are needed, which means the array is sorted. Bubble up is not an efficient sorting algorithm for large arrays as its time complexity is O(n^2) in the worst case.

// Binary Tree Node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the lowest common ancestor of two nodes in a binary tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL) {
        return root;
    }

    return left == NULL ? right : left;
}

// Driver Code
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode* p = root->left->left;
    TreeNode* q = root->left->right;

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is " << lca->val << endl;

    return 0;
}
