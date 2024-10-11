#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int n;
    typedef long long ll;
    long long t[100001][2];

    ll solve(int idx, const vector<int>& nums, bool flag) {
        if (idx >= n) {
            return 0;
        }

        if (t[idx][flag] != -1) {
            return t[idx][flag];
        }

        ll skip = solve(idx + 1, nums, flag);

        ll val = nums[idx];
        if (!flag) {
            val = -val;
        }

        ll take = solve(idx + 1, nums, !flag) + val;

        return t[idx][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, true);
    }
};

int main(){

    Solution s;

    vector<int> nums = {4,2,5,3};
    cout<<s.maxAlternatingSum(nums);
    return 0;
}