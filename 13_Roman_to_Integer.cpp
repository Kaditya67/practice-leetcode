#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int prev = 0; // Store the previous value to handle subtraction cases

        for (int i = 0; i < s.size(); ++i) {
            int cur = getValue(s[i]); // Get value for current character
            cout << "cur: " << cur << endl;
            ans += cur;
            cout << "ans: " << ans << endl;

            // Handle subtraction cases

            // Reason for Sbtracting twice:
            // prev is already added to answer, so to reduce that once and
            // we now have to remove prev from earlier answer
            if (prev < cur) {
                cout << "ans - 2 * prev: " << ans << " - 2 * " << prev << " = " << ans - 2 * prev << endl;
                ans -= 2 * prev; // Subtract twice the previous value
            }
            prev = cur;
            cout << "prev: " << prev << endl;
            cout << endl;
        }
        cout << "Final result: " << ans << endl;
        return ans;
    }

private:
    // Helper function to get integer value for Roman numeral character
    int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};

int main() {
    Solution solution;

    // // Test cases
    // string roman1 = "III";
    // cout << "Roman numeral: " << roman1 << ", Integer value: " << solution.romanToInt(roman1) << endl;

    // string roman2 = "IV";
    // cout << "Roman numeral: " << roman2 << ", Integer value: " << solution.romanToInt(roman2) << endl;

    // string roman3 = "IX";
    // cout << "Roman numeral: " << roman3 << ", Integer value: " << solution.romanToInt(roman3) << endl;

    // string roman4 = "LVIII";
    // cout << "Roman numeral: " << roman4 << ", Integer value: " << solution.romanToInt(roman4) << endl;

    string roman5 = "MCMXCIV";
    cout << "Roman numeral: " << roman5 << ", Integer value: " << solution.romanToInt(roman5) << endl;

    return 0;
}
