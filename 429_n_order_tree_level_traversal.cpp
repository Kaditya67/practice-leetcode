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
public:
    void traversal(Node* root, int depth, vector<vector<int>>& res) {
        if (!root) {
            return;
        }

        if (depth == res.size()) {
            res.push_back(vector<int>());
        }

        res[depth].push_back(root->val);
        
        for (int i = 0; i < root->children.size(); i++) {
            traversal(root->children[i], depth + 1, res);
        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        traversal(root, 0, res);

        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));

    Solution s;
    vector<vector<int>> nodes = s.levelOrder(root);
    for (vector<int> node : nodes) {
        for (int n : node) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}