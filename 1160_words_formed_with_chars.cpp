#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Solution {
public:
    int countCharacters(std::vector<std::string>& words, std::string chars) {
        std::unordered_map<char, int> charCount;

        // Count the frequency of each character in chars
        for (char c : chars) {
            charCount[c]++;
        }

        int totalLength = 0;

        // Check each word in the list of words
        for (const std::string& word : words) {
            std::unordered_map<char, int> temp = charCount;
            bool canForm = true;
            for (char ch : word) {
                if (temp[ch] > 0) {
                    temp[ch]--;
                } else {
                    canForm = false;
                    break;
                }
            }
            if (canForm) {
                totalLength += word.length();
            }
        }

        return totalLength;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> words = {"cat", "bt", "hat", "tree"};
    std::string chars = "atach";

    int result = solution.countCharacters(words, chars);
    std::cout << "Total length of words that can be formed: " << result << std::endl;

    return 0;
}
