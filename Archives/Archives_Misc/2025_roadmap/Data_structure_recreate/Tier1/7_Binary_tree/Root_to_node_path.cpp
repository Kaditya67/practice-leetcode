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

// ------------------------- Tree Builder -------------------------
/*
            10
           /  \
         2     10
        / \      \
       20  1      -25
                   /  \
                  3    4
*/

bool getPath(Node* root, int target, vector<int>&path){
    if(!root) return false;

    path.push_back(root->data);
    if(root->data == target) return true;

    if (getPath(root->left, target, path) || getPath(root->right, target, path)){
        return true;
    }

    path.pop_back(); // backtrack if not in path
    return false;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    return 0;
}
