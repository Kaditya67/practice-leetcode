#include <bits/stdc++.h>
using namespace std;

class QueueUsingStack {
private:
    stack<int> inSt;
    stack<int> outSt;

    void transfer() {
        while (!inSt.empty()) {
            outSt.push(inSt.top());
            inSt.pop();
        }
    }

public:
    void enqueue(int val) {
        inSt.push(val);
    }

    void dequeue() {
        if (outSt.empty()) transfer();

        if (!outSt.empty()) {
            outSt.pop();
        } else {
            cout << "Queue Underflow!\n";
        }
    }

    int front() {
        if (outSt.empty()) transfer();

        return outSt.empty() ? -1 : outSt.top();
    }

    bool isEmpty() {
        return inSt.empty() && outSt.empty();
    }

    int size() {
        return inSt.size() + outSt.size();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        // Copy elements into temporary stacks for display
        stack<int> tempIn = inSt, tempOut = outSt;
        vector<int> q;

        while (!tempOut.empty()) {
            q.push_back(tempOut.top());
            tempOut.pop();
        }

        reverse(q.begin(), q.end());

        stack<int> helper;
        while (!tempIn.empty()) {
            helper.push(tempIn.top());
            tempIn.pop();
        }
        while (!helper.empty()) {
            q.push_back(helper.top());
            helper.pop();
        }

        cout << "Queue: ";
        for (int val : q) cout << val << " ";
        cout << endl;
    }
};
