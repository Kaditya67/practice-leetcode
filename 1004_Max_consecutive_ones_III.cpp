#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] == 0) {
                K--; // flip a zero
            }

            while (K < 0) {
                if (A[start] == 0) {
                    K++; // restore one K
                }
                start++; // shift the window by 1
            }

            maxLen = max(maxLen, (i - start) + 1); // update maxLen
        }

        return maxLen;
    }
};

int main() {
    Solution solution;
    vector<int> A;
    int K, n, element;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        A.push_back(element);
    }

    cout << "Enter the number of flips allowed (K): ";
    cin >> K;

    int result = solution.longestOnes(A, K);
    cout << "The length of the longest subarray with at most " << K << " zero(s) flipped is: " << result << endl;

    return 0;
}
