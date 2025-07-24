// Problem: https://leetcode.com/problems/smallest-number-in-infinite-set/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> isPresent;
    int current;

public:
    SmallestInfiniteSet() {
        isPresent = vector<bool>(1001, false); 
        current = 1;
    }
    
    int popSmallest() {
        if (!pq.empty()) {
            int smallest = pq.top();
            pq.pop();
            isPresent[smallest] = false;
            return smallest;
        }
        return current++;
    }
    
    void addBack(int num) {
        if (num < current && !isPresent[num]) {
            pq.push(num);
            isPresent[num] = true;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main() {
    SmallestInfiniteSet sis;
    cout << sis.popSmallest() << endl;
    sis.addBack(2);
    cout << sis.popSmallest() << endl;
    sis.addBack(3);
    sis.addBack(1);
    cout << sis.popSmallest() << endl;
    cout << sis.popSmallest() << endl;
    cout << sis.popSmallest() << endl;
    return 0;
}

