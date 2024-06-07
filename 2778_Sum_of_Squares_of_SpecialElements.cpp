#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                ans += nums[i - 1] * nums[i - 1];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4}; // Example input

    int result = sol.sumOfSquares(nums);
    cout << "The sum of squares of elements at positions dividing the size of the array is: " << result << endl;

    return 0;
}
