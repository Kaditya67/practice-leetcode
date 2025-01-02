#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        if (n < 3) {
            return false;
        }

        int left = 0;
        int right = n - 1;
          
        while (left + 1 < n && arr[left] < arr[left + 1]) {
            ++left;
        }
         
        if (left == n - 1) {
            return false;
        }
  
        while (right - 1 >= 0 && arr[right] < arr[right - 1]) {
            --right;
        }
 
        if (right == 0) {
            return false;
        }
 
        return left == right;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> arr1 = {2, 1};
    cout << solution.validMountainArray(arr1) << endl;  // Output: 0 (false)

    // Test case 2
    vector<int> arr2 = {3, 5, 5};
    cout << solution.validMountainArray(arr2) << endl;  // Output: 0 (false)

    // Test case 3
    vector<int> arr3 = {0, 3, 2, 1};
    cout << solution.validMountainArray(arr3) << endl;  // Output: 1 (true)

    // Test case 4
    vector<int> arr4 = {1, 2, 3, 4, 5};
    cout << solution.validMountainArray(arr4) << endl;  // Output: 0 (false)

    // Test case 5
    vector<int> arr5 = {0, 1, 2, 3, 4, 5, 2, 1, 0};
    cout << solution.validMountainArray(arr5) << endl;  // Output: 1 (true)

    return 0;
}
