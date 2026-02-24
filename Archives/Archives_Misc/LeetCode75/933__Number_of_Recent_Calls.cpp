// Problem: https://leetcode.com/problems/number-of-recent-calls/
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
private:
    vector<int> records;
    int start;
public:
    RecentCounter():start(0) {}
    
    int ping(int t) {
        records.push_back(t);
        while (records[start] < t - 3000) {
            start++;
        }
        return records.size() - start;
    }
};

// Solution 2
class RecentCounter2 {
private:
    queue<int> records;
public:
    RecentCounter() {}
    
    int ping(int t) {
        records.push(t);
        while (records.front() < t - 3000) {
            records.pop();
        }
        return records.size();
    }
};

int main() {
    RecentCounter rc;
    cout << rc.ping(1) << endl;
    cout << rc.ping(100) << endl;
    cout << rc.ping(3001) << endl;
    cout << rc.ping(3002) << endl;
    return 0;
}
