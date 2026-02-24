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

    void Preorder(Node* node){
        // Value, Left, Right
        if(!node) return;
        cout<< node->data<<" ";
        Preorder(node->left);
        Preorder(node->right);
    }

    void Postorder(Node* node){
        // Left, Right, Value
        if(!node) return;
        Postorder(node->left);
        Postorder(node->right);
        cout<<node->data<<" ";
    }

    void printInorder(){
        cout<< "\nInorder Traversal : ";
        Inorder(root);
        cout<<endl;
    }

    void printPreorder(){
        cout<< "\nPreorder Traversal : ";
        Preorder(root);
        cout<<endl;
    }

    void printPostorder(){
        cout<< "\nPostOrder Traversal : ";
        Postorder(root);
        cout<<endl;
    }
};

/*
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
    */

// DFS is done using : 
// ✅ Inorder: Left -> Root -> Right            // 4,2,5,1,6,3,7
// ✅ Preorder: Root -> Left -> Right           // 1,2,4, 5, 3,6,7
// ✅ Postorder: Left -> Right -> Root          // 4,5,2,6,7,3,1

int main(){
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    bt.printInorder();  // Output: 4 2 5 1 3
    bt.printPreorder();
    bt.printPostorder();

    return 0;
}