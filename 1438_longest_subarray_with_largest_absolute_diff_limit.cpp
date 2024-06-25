// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
//         int result = 0;
//         int n = nums.size(); // Define the size of the array
//         int i = 0, j = 0;    // Initialize both pointers

//         while (j < n) {
//             int minVal = *min_element(nums.begin() + i, nums.begin() + j + 1);
//             int maxVal = *max_element(nums.begin() + i, nums.begin() + j + 1);

//             if (maxVal - minVal <= limit) {
//                 result = max(result, j - i + 1);
//                 j++;
//             } else {
//                 i++;
//             }

//             // Ensure that j is always ahead of i
//             if (i > j) {
//                 j = i;
//             }
//         }

//         return result;
//     }
// };

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int i = 0, j = 0;
        int result = 0;

        while (j < nums.size()) {
            // Maintain the maxDeque
            while (!maxDeque.empty() && nums[j] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[j]);

            // Maintain the minDeque
            while (!minDeque.empty() && nums[j] < minDeque.back()) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[j]);

            // Check if the current window is valid
            while (!maxDeque.empty() && !minDeque.empty() && (maxDeque.front() - minDeque.front() > limit)) {
                if (maxDeque.front() == nums[i]) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == nums[i]) {
                    minDeque.pop_front();
                }
                i++;
            }

            // Update result
            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 1, 2, 4, 7, 2};
    int limit = 5;

    cout << s.longestSubarray(nums, limit) << endl;

    return 0;
}


// ### Input
// ```cpp
// vector<int> nums = {10, 1, 2, 4, 7, 2};
// int limit = 5;
// ```

// ### Expected Output
// 4

// ### Dry Run

// **Initialization**:
// - `maxDeque` = []
// - `minDeque` = []
// - `i` = 0
// - `j` = 0
// - `result` = 0

// ### Iteration 1 (j = 0):
// - `nums[j] = 10`
// - Update `maxDeque`: [10]
// - Update `minDeque`: [10]
// - Difference between max and min: `10 - 10 = 0` (within limit)
// - Update `result`: `max(0, 0 - 0 + 1) = 1`
// - Increment `j`: `j = 1`

// ### Iteration 2 (j = 1):
// - `nums[j] = 1`
// - Update `maxDeque`: [10, 1]
// - Update `minDeque`: [1] (remove 10 since 1 < 10)
// - Difference between max and min: `10 - 1 = 9` (exceeds limit)
// - Shrink window by incrementing `i`: `i = 1`
//   - Remove 10 from `maxDeque` as `maxDeque.front() == nums[i]`
// - Difference between max and min: `1 - 1 = 0` (within limit)
// - Update `result`: `max(1, 1 - 1 + 1) = 1`
// - Increment `j`: `j = 2`

// ### Iteration 3 (j = 2):
// - `nums[j] = 2`
// - Update `maxDeque`: [2] (remove 1 since 2 > 1)
// - Update `minDeque`: [1, 2]
// - Difference between max and min: `2 - 1 = 1` (within limit)
// - Update `result`: `max(1, 2 - 1 + 1) = 2`
// - Increment `j`: `j = 3`

// ### Iteration 4 (j = 3):
// - `nums[j] = 4`
// - Update `maxDeque`: [4] (remove 2 since 4 > 2)
// - Update `minDeque`: [1, 2, 4]
// - Difference between max and min: `4 - 1 = 3` (within limit)
// - Update `result`: `max(2, 3 - 1 + 1) = 3`
// - Increment `j`: `j = 4`

// ### Iteration 5 (j = 4):
// - `nums[j] = 7`
// - Update `maxDeque`: [7] (remove 4 since 7 > 4)
// - Update `minDeque`: [1, 2, 4, 7]
// - Difference between max and min: `7 - 1 = 6` (exceeds limit)
// - Shrink window by incrementing `i`: `i = 2`
//   - Remove 1 from `minDeque` as `minDeque.front() == nums[i]`
// - Difference between max and min: `7 - 2 = 5` (within limit)
// - Update `result`: `max(3, 4 - 2 + 1) = 3`
// - Increment `j`: `j = 5`

// ### Iteration 6 (j = 5):
// - `nums[j] = 2`
// - Update `maxDeque`: [7, 2]
// - Update `minDeque`: [2, 4, 2] (remove 7 since 2 < 7)
// - Difference between max and min: `7 - 2 = 5` (within limit)
// - Update `result`: `max(3, 5 - 2 + 1) = 4`
// - Increment `j`: `j = 6` (end of array)

// ### Final Result
// - `result = 4`
    