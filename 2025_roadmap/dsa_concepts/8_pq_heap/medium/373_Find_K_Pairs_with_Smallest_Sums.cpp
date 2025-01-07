#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        // Priority queue to store pairs in the form of (sum, (index in nums1, index in nums2))
        priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq;

        int n = nums1.size();
        int m = nums2.size();

        // Push the first possible pair (nums1[0], nums2[0]) into the priority queue
        if (n > 0 && m > 0) {
            pq.push({nums1[0] + nums2[0], {0, 0}});
        }

        while (!pq.empty() && k > 0) {
            auto current = pq.top();
            pq.pop();
            int sum = current.first;
            int i = current.second.first;
            int j = current.second.second;
            
            ans.push_back({nums1[i], nums2[j]});
            k--;
            
            // If we can, push the next element from nums2 with the same element from nums1
            if (j + 1 < m) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
            
            // If we can, push the next element from nums1 with the same element from nums2
            if (i + 1 < n && j == 0) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    vector<vector<int>> result = sol.kSmallestPairs(nums1, nums2, k);

    // Output the result
    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;
}
