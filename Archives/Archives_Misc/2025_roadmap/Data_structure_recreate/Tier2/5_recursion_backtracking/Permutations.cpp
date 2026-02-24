#include <bits/stdc++.h>
using namespace std;

void permute(vector<int>& nums, int idx, vector<vector<int>>& result) {
    if (idx == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);
        permute(nums, idx + 1, result);
        swap(nums[idx], nums[i]);  // backtrack
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    permute(nums, 0, result);

    for (auto& perm : result) {
        for (int x : perm) cout << x << " ";
        cout << "\n";
    }
}
