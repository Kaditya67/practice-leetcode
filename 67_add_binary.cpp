#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int x = a.size() - 1;
        int y = b.size() - 1;
        char ch = '0'; // Initialize carry to '0'
        string temp;   // String to store the result

        while (x >= 0 || y >= 0) {
            char charA = (x >= 0) ? a[x] : '0';
            char charB = (y >= 0) ? b[y] : '0';

            if (charA == '1' && charB == '1' && ch == '1') {
                ch = '1';
                temp = '1' + temp;
            } else if ((charA == '1' && charB == '1') || (charA == '1' && ch == '1') || (charB == '1' && ch == '1')) {
                ch = '1';
                temp = '0' + temp;
            } else if (charA == '0' && charB == '0' && ch == '0') {
                ch = '0';
                temp = '0' + temp;
            } else {
                ch = '0';
                temp = '1' + temp;
            }

            x--;
            y--;
        }

        // Check if there's any carry left
        if (ch == '1') {
            temp = '1' + temp;
        }

        return temp;
    }
};


int main() {
    string a, b;
    cin >> a >> b;
    Solution s;
    cout << s.addBinary(a, b);

    return 0;
}