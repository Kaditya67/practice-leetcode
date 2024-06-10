#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;  // Copy the original heights array
        sort(sortedHeights.begin(), sortedHeights.end());  // Sort the copied array
        
        int count = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sortedHeights[i]) {  // Compare original and sorted arrays
                count++;
            }
        }
        
        return count;  // Return the count of out-of-order elements
    }
};

int main() {
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    Solution sol;   

    int result = sol.heightChecker(heights);
    cout << "Output: " << result << endl;  // Expected output is 3

    return 0;
}

// Expected Output:  1 1 1 2 3 4
// Given heights :   1 1 4 2 1 3
// count all misplaced peole from their position