// Problem: https://leetcode.com/problems/bitwise-ors-of-subarrays
// Difficulty: Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result, current;
        for(int num:arr){
            unordered_set<int> next;
            next.insert(num);
            for(int x:current){     // Extend the previous ORs with the current number
                next.insert(x | num);
            }
            current = next;        // Update current ORs
            for(int x:current){
                result.insert(x);  // Add all current ORs to the result set
            }
        }
        return result.size();  // Return the size of the result set
    }
};  

int main()
{
    Solution s;
    vector<int> arr = {1,1,2};

    cout << s.subarrayBitwiseORs(arr) << endl;
    return 0;
}
