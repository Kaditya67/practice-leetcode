// Problem: https://leetcode.com/problems/unique-number-of-occurrences/
// Difficulty: Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int num:arr){
            mp[num]++;
        }

        unordered_set<int>s;
        for(auto &[n,f]:mp){
            if(s.empty() || s.find(f)==s.end()) s.insert(f);
            else{
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << boolalpha << s.uniqueOccurrences(arr) << endl; // Expected output: true

    vector<int> arr2 = {1, 2};
    cout << boolalpha << s.uniqueOccurrences(arr2) << endl; // Expected output: false

    return 0;
}

