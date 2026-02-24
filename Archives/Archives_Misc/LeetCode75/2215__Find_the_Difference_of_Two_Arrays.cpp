// Problem: https://leetcode.com/problems/find-the-difference-of-two-arrays/
// Difficulty: Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1;
        unordered_set<int>s2;
        for(int num:nums1) s1.insert(num);
        for(int num:nums2) s2.insert(num);

        vector<int> res1;
        vector<int> res2;
        for(int s:s1){
            if(s2.find(s)==s2.end()){
                res1.push_back(s);
            }
        }
        for(int s:s2){
            if(s1.find(s)==s1.end()){
                res2.push_back(s);
            }
        }
        return {res1,res2};
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {3, 4, 5, 6};
    vector<vector<int>> result = s.findDifference(nums1, nums2);

    cout << "Elements in nums1 but not in nums2: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Elements in nums2 but not in nums1: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

