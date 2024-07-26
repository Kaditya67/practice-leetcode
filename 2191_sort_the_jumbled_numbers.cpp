#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mpResult;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            string strNum = to_string(nums[i]);
            string temp;
            
            for (char ch : strNum) {
                int num = ch - '0'; // Convert char to int
                temp += to_string(mapping[num]); // Append mapped value as string
            }
            
            mpResult[nums[i]] = stoi(temp); // Convert temp string to int and store in map
            
            // Debugging: Print mapped values
            cout << "Original: " << nums[i] << " -> Mapped: " << temp << endl;
        }
        
        // Sort the nums based on their mapped values
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return mpResult[a] < mpResult[b];
        });
        
        // Debugging: Print sorted numbers
        cout << "Sorted nums: ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        
        return nums;
    }
};

int main() {
    Solution solution;
    vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
    vector<int> nums = {990, 332, 981, 321, 898};
    
    vector<int> result = solution.sortJumbled(mapping, nums);
    
    // Print the result
    cout << "Final Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
