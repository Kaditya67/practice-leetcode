#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        for (string &word : words) {
            for (int i = 0; i < n; i++) {
                if (words[i] == word) {
                    continue;
                }
                if (words[i].find(word) != string::npos) {
                    result.push_back(word);
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    // Example test case
    vector<string> words = {"mass", "as", "hero", "superhero"};
    
    Solution solution;
    vector<string> result = solution.stringMatching(words);

    // Output the result
    cout << "Substrings found: ";
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
