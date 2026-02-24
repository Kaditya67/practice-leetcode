#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

class BinaryTree{
private:
    Node* root;
public:
    BinaryTree(){
        root = nullptr;
    }

    Node* getRoot() {
        return root;
    }

    void insert(int val){
        Node* newNode = new Node(val);
        if(!root){
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(!temp->left){    // If this doesn't exist, Assign here
                temp->left = newNode;
                return;
            }else{
                q.push(temp->left); // We will also need to traverse this
            }

            if(!temp->right){
                temp->right = newNode;
                return;
            }else{
                q.push(temp->right);
            }
        }
    }

    void Inorder(Node* node){
        // Left, Value, Right
        if(!node) return;
        Inorder(node->left);
        cout<< node->data <<" ";
        Inorder(node->right);
    }

    void printInorder(){
        cout<< "\nInorder Traversal : ";
        Inorder(root);
        cout<<endl;
    }

    void storeInorder(Node* root, vector<int>& inorder) {       // Traverse Tree and store all values
        if (!root) return;
        storeInorder(root->left, inorder);
        inorder.push_back(root->data);      // Store value
        storeInorder(root->right, inorder);
    }

    void arrayToBST(Node* root, vector<int>& inorder, int& index) {     // Inorder and just store the sorted values in their place
        if (!root) return;
        arrayToBST(root->left, inorder, index);
        root->data = inorder[index++];      // store the value and move to next index
        arrayToBST(root->right, inorder, index);
    }

    void binaryTreeToBST(Node* root) {
        vector<int> inorder;
        storeInorder(root, inorder);
        sort(inorder.begin(), inorder.end());
        int index = 0;
        arrayToBST(root, inorder, index);
    }
};

int main(){
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);

    bt.printInorder();  // Original Binary Tree inorder: 4 2 5 1 3

    // 🔁 Convert to BST
    cout<<"Coverting to BST... "<<endl;
    bt.binaryTreeToBST(bt.getRoot());  // ← Call this!

    bt.printInorder();  // Should now print a sorted sequence: 1 2 3 4 5

    return 0;
}
