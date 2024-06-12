#include <iostream>
#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        // Convert the string to lowercase
        for (char& c : s) {
            c = std::tolower(c);
        }

        // Initialize pointers
        int left = 0;
        int right = s.size() - 1;

        // Move pointers towards each other until they meet
        while (left < right) {
            // Skip non-alphanumeric characters
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            // Compare characters
            if (s[left] != s[right]) {
                return false;
            }

            // Move pointers
            left++;
            right--;
        }
        return true;
    }
};

int main() {

    std::string s = "A man, a plan, a canal: Panama";

    Solution obj;

    std::cout << obj.isPalindrome(s) << std::endl;

    return 0;

}