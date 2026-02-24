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

    void printInorder(){
        cout<< "\nInorder Traversal : ";
        Inorder(root);
        cout<<endl;
    }
};

int main(){
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);

    bt.printInorder();  // Output: 4 2 5 1 3
    return 0;
}