#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) {
            cout<<"sum+num: "<<sum<<" + "<<num<<" % "<<p<<" = ";
            sum = (sum + num) % p;
            cout<<sum<<endl;
        }
        cout<<"Total sum: "<<sum<<endl;
        if (sum == 0) {
            return 0;
        }
        unordered_map<int, int> preSums;
        preSums[0] = -1;
        int result = n;
        for (int i = 0, preSum = 0; i < n; i++) {
            cout<<"preSum: "<<preSum<<" + "<<nums[i]<<" % "<<p<<" = ";
            preSum = (preSum + nums[i]) % p;            // store remainder
            cout<<preSum<<endl;

            int x = (p + preSum - sum) % p;         // Main calculation
            cout<<"p+preSum-sum: "<<p<<"+"<<preSum<<"-"<<sum<<"="<<x<<endl;

            if (preSums.find(x) != preSums.end()) {
                cout<<"Already present remainder: "<<x<<endl;
                result = min(result, i - preSums[x]);
                cout<<"result: "<<result<<endl;
            }
            preSums[preSum] = i;
            cout<<"Adding it to Map..."<<endl<<endl;
        }
        if (result == n) {
            return -1;
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {3, 1, 4, 2};
    int p1 = 6;
    cout << "Test case 1: " << solution.minSubarray(nums1, p1) << endl; // Output: 1

    // // Test case 2
    // vector<int> nums2 = {6, 3, 5, 2};
    // int p2 = 9;
    // cout << "Test case 2: " << solution.minSubarray(nums2, p2) << endl; // Output: 2

    // // Test case 3
    // vector<int> nums3 = {1, 2, 3};
    // int p3 = 7;
    // cout << "Test case 3: " << solution.minSubarray(nums3, p3) << endl; // Output: -1

    return 0;
}


// dry run

// 3,1,4,2
// p=6

// 3+1+2=6
// remove 4 i.e 1 element

// if the length of array is 4

// if two subarray makes the total sum of p then result is 2
// if three subarray makes the total sum of p then result is 1
// if 4 subarray makes the total sum  of p then result is 0
// if more than 4 subarray is required then result is -1

// remainder    | count 
// 0            | -1        ---> 2
// 5            | 1
// 4            