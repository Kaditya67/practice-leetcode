// Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;     // Max Heap

        for(int num : nums){
            pq.push(num);
        }

        for(int i=1;i<k;i++){
            pq.pop();
        }
        return pq.top();
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;  // Min Heap

        for(int num : nums){
            if(pq.size() < k){
                pq.push(num);
            }else{
                if(num > pq.top()){
                    pq.pop();
                    pq.push(num);
                }
            }
        }

        return pq.top();
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << s.findKthLargest(nums,k) << endl;
    return 0;
}
