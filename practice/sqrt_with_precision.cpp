#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double morePrecision(int n, int precision, int tempSol) {
        double factor = 1;
        double ans = tempSol;
        for (int i = 0; i < precision; i++) {
            factor = factor / 10;
            for (double j = ans; j * j < n; j = j + factor) {
                ans = j;
            }
        }
        return ans;
    }

    int mySqrt(int x) {
        if (x == 1 || x == 0) {
            return x;
        }
        long left = 1, right = x;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long square = mid * mid;

            if (square == x) {
                return mid;
            }
            else if (square < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};

int main() {
    Solution sol;
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int intSqrt = sol.mySqrt(number);
    double preciseSqrt = sol.morePrecision(number, 3, intSqrt);

    cout << "The integer square root of " << number << " is: " << intSqrt << endl;
    cout << "The precise square root of " << number << " is: " << preciseSqrt << endl;

    return 0;
}
