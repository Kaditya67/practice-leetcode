#include<bits/stdc++.h>
using namespace std;


class MinMaxStack{
private:
    stack<int> st;  // Main Stack
    stack<int> minSt;   // Min Stack    // Always keep min value on top --> Stack reducing values
    stack<int> maxSt;   // Max Stack    // Always keep max value on the top ---> Stack increasing values

public:
    void push(int val){
        st.push(val);

        if(minSt.empty() || minSt.top() > val){
            minSt.push(val);
        }

        // Update maxStack — must not be in else-if!
        if(maxSt.empty() || maxSt.top() < val){
            maxSt.push(val);
        }
    }

    void pop(){
        if(st.empty()){
            cout<<"Stack is Empty!\n";
            return;
        }

        // Note :  We can use {key:value} pair to avoid rechecking into stacks and just pop from all
        int val = st.top();
        st.pop();
        if(val==minSt.top()) minSt.pop();
        if(val==maxSt.top()) maxSt.pop();
    }

    int top(){
        if(st.empty()) return -1;
        return st.top();
    }

    int getMin(){
        if(minSt.empty()) return -1;
        return minSt.top();
    }

    int getMax(){
        if(maxSt.empty()) return -1;
        return maxSt.top();
    }

    bool isEmpty() {
        return st.empty();
    }

    int size() {
        return st.size();
    }

    void display() {
        stack<int> temp = st;
        while (!temp.empty()) {
            cout << temp.top() << endl;
            temp.pop();
        }
        cout << "Stack (top to bottom): ";
        cout << endl;
    }

};

int main() {
    MinMaxStack s;

    s.push(5);
    s.push(1);
    s.push(3);
    s.push(1);
    s.push(6);
    s.push(1);

    cout << "Current Stack:" << endl;
    s.display();

    cout << "Top: " << s.top() << endl;        // 1
    cout << "Min: " << s.getMin() << endl;     // 1
    cout << "Max: " << s.getMax() << endl;     // 6

    cout << "\nPopping 3 elements...\n";
    s.pop(); // pops 1
    s.pop(); // pops 6
    s.pop(); // pops 1

    cout << "After pops:" << endl;
    s.display();
    cout << "Top: " << s.top() << endl;        // 3
    cout << "Min: " << s.getMin() << endl;     // 1
    cout << "Max: " << s.getMax() << endl;     // 5

    return 0;
}
