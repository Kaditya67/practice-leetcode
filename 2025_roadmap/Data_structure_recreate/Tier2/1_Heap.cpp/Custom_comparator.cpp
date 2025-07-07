#include<bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second>b.second;   // 1st is greater than second ---> Min Heap by second part
    }
};

priority_queue<pair<int,int>,vector<pair<int,int>>, compare> pq;

int main() {
    // Push pairs: (element, frequency)
    pq.push({1, 5});
    pq.push({2, 3});
    pq.push({3, 7});
    pq.push({4, 1});

    cout << "Elements in Min Heap order (by second):\n";
    while (!pq.empty()) {
        auto p = pq.top();
        cout << "(" << p.first << ", " << p.second << ") ";
        pq.pop();
    }
    cout << endl;

    return 0;
}