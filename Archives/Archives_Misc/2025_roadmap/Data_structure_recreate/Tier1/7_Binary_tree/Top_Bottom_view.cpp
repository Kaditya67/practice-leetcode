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

    void levelOrder(Node *node){
        if(!root) return;

        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            cout<<curr->data<<" ";  // Print

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }

    void printPostorder(){
        cout<< "\nPostOrder Traversal : ";
        Postorder(root);
        cout<<endl;
    }

    void printLevelOrder(){
        cout<<"\n Level Order Traversal : ";
        levelOrder(root);
        cout<<endl;
    }

    int diameterHelper(Node* root,int &diameter){
        if(!root) return 0;

        int left = diameterHelper(root->left,diameter);
        int right = diameterHelper(root->right,diameter);

        diameter = max(diameter,left+right);
        return 1+max(left,right);
    }

    int getDiameter() {
        int diameter = 0;
        diameterHelper(root, diameter);
        return diameter;
    }

    void leftView(){
        if(!root) return;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();

            for(int i=0;i<n;i++){
                Node* curr = q.front();
                q.pop();
                if(i==0) cout<<curr->data<<" ";
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        cout<<endl;
    }

    void rightView(){
        if(!root) return;
        queue<Node*> q;     // Level order
        q.push(root);
        while(!q.empty()){
            int n = q.size();

            for(int i=0;i<n;i++){
                Node* curr = q.front();
                q.pop();
                if(i==n-1) cout<<curr->data<<" ";
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        cout<<endl;
    }

    void topView(){
        if(!root) return;
        map<int,Node*> mp;    // HD -> Node
        queue<pair<Node*,int>> q; // {node, HD}

        q.push({root,0});
        while(!q.empty()){
            auto [node, hd] = q.front();    q.pop();
            if(!mp.count(hd)){
                mp[hd]=node;
            }
            if(node->left) q.push({node->left,hd-1});
            if(node->right) q.push({node->right,hd+1});
        }
        cout<< "Top View : ";
        for(auto [hd,node]:mp){
            cout<<node->data<<" ";
        }
        cout<<endl;
    }

    void bottomView(){
        if(!root) return;
        map<int,Node*> mp;    // HD -> Node
        queue<pair<Node*,int>> q; // {node, HD}

        q.push({root,0});
        while(!q.empty()){
            auto [node, hd] = q.front();    q.pop();
            mp[hd]=node;
            if(node->left) q.push({node->left,hd-1});
            if(node->right) q.push({node->right,hd+1});
        }
        cout<< "Bottom View : ";
        for(auto [hd,node]:mp){
            cout<<node->data<<" ";
        }
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

// BFS is Level Order Traversal

int main(){
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);
    bt.insert(8);

    bt.printInorder();  // Output: 4 2 5 1 3
    bt.printPreorder();
    bt.printPostorder();
    bt.printLevelOrder();

    cout << "\nDiameter of Tree : " << bt.getDiameter() << endl;
    cout<< "\nLeft View of Tree : " ;
    bt.leftView();

    cout<< "\nRight View of Tree : " ;
    bt.rightView();

    bt.topView();
    bt.bottomView();
    return 0;
}