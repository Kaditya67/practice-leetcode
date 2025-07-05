// Input:
//         1
//        / \
//       2   3
//      / \   \
//     4  5    7

// Queue: [1]
// → Pop 1, push 2, 3  
// → Pop 2, push 4, 5  
// → Pop 3, push NULL, 7  
// → Pop 4 → push NULL, NULL  
// → Pop 5 → push NULL, NULL  
// → Pop NULL → nullSeen = true  
// → Pop 7 ❌ Found node **after** nullSeen = true → return false

// Not filled from left to right

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

    bool isComplete(){
        if(!root) return true;

        queue<Node*>q;
        q.push(root);
        bool nullSeen = false;
        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            if(!curr) nullSeen=true;
            else{   // Do not enter here after any NULL seen
                if(nullSeen) return false;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
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
    cout << "Is Binary Tree Complete? " << ((bt.isComplete() == 1) ? "Yes" : "No") << endl;
    
    return 0;
}