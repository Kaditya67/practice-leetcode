#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        int sum = 0;
        int count = 0;
        
        // Initialize the map with the base case
        prefixSumCount[0] = 1;
        
        for (int num : nums) {
            sum += num;
            cout<<"Sum is : "<<sum<<endl;
            
            // Check if there is a prefix subarray we can subtract to reach the desired sum
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
                cout<<"Count is : "<<count<<endl;
            }
            
            // Update the count of the current prefix sum in the map
            prefixSumCount[sum]++;
            cout<<"Prefix sum count is : "<<prefixSumCount[sum]<<endl;
            cout<<"\n"<<endl;
        }
        
        return count;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    int result1 = solution.subarraySum(nums1, k1);
    cout << result1 << endl;  // Output: 2

    // Test case 2
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    int result2 = solution.subarraySum(nums2, k2);
    cout << result2 << endl;  // Output: 2

    return 0;
}
