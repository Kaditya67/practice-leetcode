#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){  data= val; next = nullptr;}
};

class SingleLinkedList{
private:
    Node* head;
    Node* tail;

public:
    SingleLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int val){
        if(head==nullptr){
            Node* newNode = new Node(val);
            head = newNode;
            tail = newNode;
        }
        else{
            Node* newNode = new Node(val);
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // head -> [1] -> [2] -> [3] -> nullptr
    //                        ↑
    //                       tail
    Node* reverse(){
        Node* next = nullptr;
        Node* prev = nullptr;
        Node* curr = head;       // Head is a pinter to the first Node

        tail = head;                // Update tail to the current head
        while(curr!=nullptr){
            next = curr->next;     // Store the next Node
            curr->next = prev;     // Reverse the link
            prev = curr;           // Move prev to current Node
            curr = next;           // Move to the next Node
        }
        head = prev;
        return head;
    }
};

int main(){
    SingleLinkedList sll;
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(3);
    cout << "Original List: ";
    sll.display();

    sll.reverse();
    cout << "Reversed List: ";
    sll.display();
    return 0;
}