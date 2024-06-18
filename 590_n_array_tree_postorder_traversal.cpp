#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
private:
    void postorderHelper(Node* node, vector<int>& nodes) {
        if (node == nullptr) {
            return;
        }

        // Traverse all children first
        for (Node* child : node->children) {
            postorderHelper(child, nodes);
        }

        // Visit the current node after all children are processed
        nodes.push_back(node->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> nodes;

        if (root == nullptr) {
            return nodes;  // Return empty vector if root is null
        }

        postorderHelper(root, nodes);
        return nodes;
    }
};

int main(){
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));

    Solution s;
    vector<int> nodes = s.postorder(root);
    for (int node : nodes) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}