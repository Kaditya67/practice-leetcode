#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        std::vector<int> temp;
        int original_num = num;

        while (num > 0) {
            int t = num % 10;
            temp.push_back(t);
            num /= 10;
        }
        std::reverse(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); i++) {
            int maxEvenIndex = -1;
            int maxOddIndex = -1;

            // Find the largest even number at or after i
            if (temp[i] % 2 == 0) {
                for (int j = i; j < temp.size(); j++) {
                    if (temp[j] % 2 == 0 && (maxEvenIndex == -1 || temp[j] > temp[maxEvenIndex])) {
                        maxEvenIndex = j;
                    }
                }
                if (maxEvenIndex != -1 && maxEvenIndex != i) {
                    std::swap(temp[i], temp[maxEvenIndex]);
                }
            }

            // Find the largest odd number at or after i
            if (temp[i] % 2 != 0) {
                for (int j = i; j < temp.size(); j++) {
                    if (temp[j] % 2 != 0 && (maxOddIndex == -1 || temp[j] > temp[maxOddIndex])) {
                        maxOddIndex = j;
                    }
                }
                if (maxOddIndex != -1 && maxOddIndex != i) {
                    std::swap(temp[i], temp[maxOddIndex]);
                }
            }
        }

        // Reconstruct the number from the digits
        long long int res = 0;
        for (int i = 0; i < temp.size(); i++) {
            res = res * 10 + temp[i];
        }

        return res;
    }
};


int main() {
    Solution s;
    int num = 1234;
    cout << s.largestInteger(num) << endl;
    return 0;
}