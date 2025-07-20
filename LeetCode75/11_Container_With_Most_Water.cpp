// Problem: https://leetcode.com/problems/container-with-most-water/
// Difficulty: Medium

#include<bits/stdc++.h>
using namespace std;

// Place two pointers: one at the beginning left = 0, and one at the end right = n - 1.
// At each step:
// Calculate the current area.
// Move the shorter line's pointer inward, because moving the taller one cannot increase area.
// Repeat until left < right

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;

        int maxArea = INT_MIN;
        while(left<right){
            int width = right - left;
            maxArea = max(maxArea,(width*min(height[left],height[right])));
            (height[left]<=height[right])?left++:right--;
        }
        return maxArea;
    }
};

int main() {
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(height) << endl;
    return 0;
}

