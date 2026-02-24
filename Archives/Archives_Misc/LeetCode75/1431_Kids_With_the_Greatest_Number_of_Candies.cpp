// Problem: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
// Difficulty: Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxNum = *max_element(candies.begin(),candies.end());   // Find the maximum candy
        vector<bool> res;
        for(int c:candies){
            if((c+extraCandies)>=maxNum){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> candies = {2,3,5,1,3};
    int extraCandies = 3;
    vector<bool> res = s.kidsWithCandies(candies,extraCandies);
    for(bool b:res) cout << b << " ";
    cout << endl;
    return 0;
}
