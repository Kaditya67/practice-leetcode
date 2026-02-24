// Problem: https://leetcode.com/problems/increasing-triplet-subsequence/
// Difficulty: Medium
// Concept: Greedy
//* You're not backtracking or checking all possible triplets — just the first valid one, which is a greedy strategy.

//! Get Excited: New Concept Unlocked!
// {2,1,5,0,4,6}
// After sorted : {0,1,2,4,5,6}
// 1st Smallest = 0
// 2nd Smallest = 1
// 3rd Smallest = 2 ....

//? How to find the 2nd/3rd Smallest Number in the array without sorting...?
//! Note: If you find "running" 3rd Smallest, the problem is solved..!!

//* Algorithm: (Only see, if you can guess by Code)
//// Keep updating 1st if you keep finding smaller numbers
//// If a greater number than 1st is found, keep updating second and if greater than second found, keep updating 3rd and so on...


#include<bits/stdc++.h>
using namespace std;

// Greedy Solution
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                first = num;  // smallest so far
            } else if (num <= second) {
                second = num; // second smallest
            } else {
                return true;   // third number > second ⇒ triplet found
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << boolalpha << s.increasingTriplet(nums) << endl; // Expected output: true
    return 0;
}