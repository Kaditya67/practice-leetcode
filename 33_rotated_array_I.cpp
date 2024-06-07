#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end, int key) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == key) {
                return mid;
            } else if (nums[mid] > key) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }

    int getPivot(vector<int>& nums, int start, int end) {
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= nums[0]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int pivot = getPivot(nums, 0, n - 1);

        // If we found the target at the pivot
        if (nums[pivot] == target) {
            return pivot;
        }

        // If the pivot is 0, it means the array is not rotated
        if (pivot == 0) {
            return binarySearch(nums, 0, n - 1, target);
        }

        // Decide which part to search
        if (target >= nums[0] && target <= nums[pivot - 1]) {
            return binarySearch(nums, 0, pivot - 1, target);
        } else {
            return binarySearch(nums, pivot, n - 1, target);
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = sol.search(nums, target);
    cout << "Output: " << result << endl;  // Expected output is 4
    return 0;
}
