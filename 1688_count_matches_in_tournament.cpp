#include <iostream>

class Solution {
public:
    int numberOfMatches(int n) {
        int cnt = 0;

        while (n > 1) {
            if (n % 2 == 0) {
                cnt += n / 2;
                n = n / 2;
            } else {
                cnt += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }

        return cnt;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    int n1 = 7;  // Expected matches: 6
    int n2 = 14; // Expected matches: 13

    std::cout << "Number of matches for " << n1 << ": " << solution.numberOfMatches(n1) << std::endl;
    std::cout << "Number of matches for " << n2 << ": " << solution.numberOfMatches(n2) << std::endl;

    return 0;
}
