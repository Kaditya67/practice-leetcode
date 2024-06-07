#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 1 || x == 0) {
            return x;
        }
        long left = 1, right = x;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            cout<<"mid : "<<mid<<endl;
            long square = mid * mid;
            cout<<"square : "<<square<<endl;

            if (square == x) {
                return mid;
            }
            else if (square < x) {
                left = mid + 1;
                cout<<"left : "<<left<<endl;
            }
            else {
                right = mid - 1;    // keep decreasing the middle until you find the correct closest square
                cout<<"right : "<<right<<endl;
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

    int result = sol.mySqrt(number);
    cout << "The integer square root of " << number << " is: " << result << endl;

    return 0;
}
