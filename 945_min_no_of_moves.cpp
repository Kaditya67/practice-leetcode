#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());
        int moves = 0;

        // Iterate through the sorted array
        for (int i = 1; i < nums.size(); i++) {
            cout<<nums[i]<<" - "<<nums[i - 1]<<endl;
            if (nums[i] <= nums[i - 1]) {
                int increment = nums[i - 1] + 1 - nums[i];
                cout<<"nums["<<(i-1)<<"]+ 1 - nums["<<i<<"] : "<<nums[i - 1]<<" - "<<nums[i]<<" + 1 = "<<increment<<endl;
                cout<<"Increment: "<<increment<<endl;
                nums[i] += increment;
                cout<<"Updated: "<<nums[i]<<endl;
                moves += increment;
                cout<<"Moves: "<<moves<<endl;
            }

            cout<<endl;
        }

        return moves;
    }
};

int main() {
    Solution s;

    vector<int> nums = {3, 2, 1, 2, 1, 7};

    cout << s.minIncrementForUnique(nums) << endl;

    return 0;
}
