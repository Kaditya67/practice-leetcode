#include<iostream>
using namespace std;

class Solution {
public:
    // Counts the number of integers with prefix 'curr' within the range [1, n]
    int countWithPrefix(long curr, long next, int n) {
        int count = 0;
        while (curr <= n) {
            count += min(next, (long)n + 1) - curr;
            curr *= 10;
            next *= 10;
        }
        return count;
    }

    // Finds the k-th lexicographical number in the range [1, n]
    int findKthNumber(int n, int k) {
        if (k < 1 || k > n) {
            return -1; // Invalid input
        }
        
        int curr = 1;
        k--; // We already count '1' as the first number

        while (k > 0) {
            int count = countWithPrefix(curr, curr + 1, n);
            
            if (count <= k) {
                // Skip this prefix, move to the next lexicographical number
                curr++;
                k -= count;
            } else {
                // Dive deeper into this prefix by adding another digit
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};

int main() {
    Solution s;
    
    // Test with valid inputs
    cout << s.findKthNumber(13, 2) << endl;  // Expected output: 10
    cout << s.findKthNumber(100, 10) << endl; // Expected output: 17
    
    // Test with invalid input
    cout << s.findKthNumber(3, 9) << endl;   // Expected output: -1 (invalid input)
    
    return 0;
}
