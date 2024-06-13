#include <iostream>
using namespace std;

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int arr[n];
        for(int i = 0; i < n; i++) {
            arr[i] = 1;
        }
        while(k-- > 0) {
            long long preSum = 0;
            for(int i = 0; i < n; i++) {
                preSum += arr[i];
                arr[i] = preSum % 1000000007;       // mod by this large number is that number only
                // The number remains within the range 
            }
            cout << "Array after " << k << " seconds: ";
            for(int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return arr[n - 1];
    }
};

int main() {
    Solution sol;
    int n = 4, k = 5;
    cout << "Value after " << k << " seconds: " << sol.valueAfterKSeconds(n, k) << endl;

    return 0;
}
