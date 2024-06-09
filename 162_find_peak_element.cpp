#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {    // Run until low is less than high
            int mid = low + (high - low) / 2;
            cout << "mid: " << mid << endl;

            cout << "nums[mid] < nums[mid+1]: " << (nums[mid] < nums[mid + 1]) << endl;
            if (nums[mid] < nums[mid + 1]) {      // If middle element is shorter than its right neighbor
                cout<<"Right Neighbout is greater than mid"<<endl;
                // Start from the right neighbor
                low = mid + 1;
                cout << "low: " << low << endl;
            } else {
                high = mid;   // If middle is greater than its right neighbor
                // End at the middle
                cout << "high: " << high << endl;
            }
            cout << "---" << "\n" << endl;
        }
        cout << "low: " << low << endl;
        cout << "high: " << high << endl;
        return low;
    }

};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int peakIndex = solution.findPeakElement(nums);
    cout << "Peak element index: " << peakIndex << endl;
    return 0;
}

