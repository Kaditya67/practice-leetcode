// Problem: https://leetcode.com/problems/find-the-highest-altitude/
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int maxGain = 0;
        for(int i=0;i<gain.size();i++){
            sum += gain[i];
            maxGain = max(sum,maxGain);
        }
        return maxGain;
    }
};

int main() {
    Solution s;
    vector<int> gain = {-5,1,5,0,-3};
    cout << s.largestAltitude(gain) << endl;
    return 0;
}

