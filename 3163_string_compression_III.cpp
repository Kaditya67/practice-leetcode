#include <string>
#include <iostream>

class Solution {
public:
    std::string compressedString(std::string word) {
        std::string comp; // Resultant compressed string

        int n = word.size(); // Length of the input string
        for (int i = 0; i < n;) {
            char chosenChar = word[i]; // The current character being processed
            int count = 0; // Count of consecutive characters

            // Count consecutive characters, ensuring count does not exceed 9
            while (i < n && word[i] == chosenChar && count < 9) {
                count++;
                i++;
            }

            // Push the count (as a character) and the character itself to the result
            comp.push_back(count + '0'); // Convert count to character and add to result
            comp.push_back(chosenChar);    // Add the character itself
        }

        return comp; // Return the final compressed string
    }
};

int main() {
    Solution solution;
    std::string input;
    
    std::cout << "Enter a string to compress: ";
    std::cin >> input;

    std::string compressed = solution.compressedString(input);
    std::cout << "Compressed string: " << compressed << std::endl;

    return 0;
}
