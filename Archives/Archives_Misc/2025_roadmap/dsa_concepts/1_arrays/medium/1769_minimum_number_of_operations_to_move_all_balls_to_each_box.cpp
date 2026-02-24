#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        // Single pass: calculate moves from both left and right
        for (int i = 0; i < n; i++) {
            // Left pass
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            // Right pass
            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }

        return answer;
    }
};

int main() {
    Solution solution;
    string boxes;

    // Input test cases
    cout << "Enter the binary string representing boxes: ";
    cin >> boxes;

    vector<int> result = solution.minOperations(boxes);

    // Output the results
    cout << "Minimum operations to move all balls to each box: ";
    for (int moves : result) {
        cout << moves << " ";
    }
    cout << endl;

    return 0;
}
