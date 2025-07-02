#include<bits/stdc++.h>

using namespace std;

class Node{     // Use Class for Encapsulation          // Struct is public by default
public:
    int data;
    Node* next;

    Node(int val){  // Constructor
        data = val;
        next = nullptr;
    }
};

class SingleLinkedList{
private:
    Node* head;
public:
    SingleLinkedList(){
        head = nullptr;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(head==nullptr){
            head = newNode;
            return;
        }
        // Iterate and reach the end
        Node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteByValue(int val){
        if(head==nullptr){
            return;
        }

        Node*temp = head;
        if(temp->data == val){      // 1st Node
            head = head->next;
            delete temp;
            return;
        }
        while(temp->next->data!=val && temp->next != nullptr){  // From 2nd Node and ahead
            temp = temp->next;
        }
        if(temp->next==nullptr) return; // If we reach the end of the list, value not found --> return 

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    bool search(int val){
        Node* temp = head;
        while(temp->data!=val && temp->next!=nullptr){
            temp = temp->next;
        }
        if(temp->data==val) return true;
        return false;
    }

    void display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    Node* getHead(){
        return head;
    }

    Node* setHead(Node* newHead){
        Node* oldHead = head;
        head = newHead;
        return oldHead;
    }
};

int main(){
    SingleLinkedList sll;
    sll.insertAtHead(3);
    sll.insertAtHead(2);
    sll.insertAtHead(1);
    sll.insertAtEnd(4);
    sll.insertAtEnd(5);
    sll.insertAtEnd(6);
    sll.display();
    sll.deleteByValue(3);
    sll.display();
    cout<<sll.search(3)<<endl;

    return 0;
}