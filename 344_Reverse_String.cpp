#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            char temp = s[i];  // Use char instead of int for the temporary variable
            s[i] = s[j];
            s[j] = temp;
            i++;  // Increment i to move towards the center
            j--;  // Decrement j to move towards the center
        }
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s1);
    for (char c : s1) {
        cout << c << " ";
    }
    cout << endl;

    // Test case 2
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    solution.reverseString(s2);
    for (char c : s2) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
