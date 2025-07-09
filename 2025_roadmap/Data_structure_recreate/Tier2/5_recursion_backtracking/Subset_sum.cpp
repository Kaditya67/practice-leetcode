#include <bits/stdc++.h>
using namespace std;

void subsetSum(int idx, vector<int>& nums, int target, vector<int>& curr, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(curr);
        return;
    }
    if (idx == nums.size() || target < 0) return;

    // Pick current element
    curr.push_back(nums[idx]);
    subsetSum(idx + 1, nums, target - nums[idx], curr, result);
    curr.pop_back();  // backtrack

    // Skip current element
    subsetSum(idx + 1, nums, target, curr, result);
}

int main() {
    vector<int> nums = {2, 3, 5, 7};
    int target = 10;
    vector<int> curr;
    vector<vector<int>> result;

    subsetSum(0, nums, target, curr, result);

    for (auto& subset : result) {
        for (int x : subset) cout << x << " ";
        cout << "\n";
    }
}
