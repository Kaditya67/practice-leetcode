#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int n = chars.size();
        if (n == 0) return 0;
        
        int index = 0; // Index to place the compressed characters
        int i = 0;
        
        while (i < n) {
            char current_char = chars[i];
            int count = 0;
            
            // Count occurrences of the current character
            while (i < n && chars[i] == current_char) {
                i++;
                count++;
            }
            
            // Place the character
            chars[index++] = current_char;
            
            // Place the count if greater than 1
            if (count > 1) {
                for (char c : std::to_string(count)) {
                    chars[index++] = c;
                }
            }
        }
        
        return index;
    }
};

int main() {
    Solution solution;
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int compressed_length = solution.compress(chars);
    std::cout << "Compressed length: " << compressed_length << std::endl;
    std::cout << "Compressed characters: ";
    for (int i = 0; i < compressed_length; ++i) {
        std::cout << chars[i];
    }
    std::cout << std::endl;
    return 0;
}
