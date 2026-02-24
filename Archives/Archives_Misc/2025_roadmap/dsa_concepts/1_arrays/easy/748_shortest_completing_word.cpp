#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> freq(26, 0);
        int count = 0;
         
        for (char c : licensePlate) {
            if (isalpha(c)) {
                freq[tolower(c) - 'a']++;
                count++;
            }
        }

        string result = "";
         
        for (const string& word : words) {
            if (word.size() < count) continue; 
            int tempCount = count;
            vector<int> tempFreq(freq);
            for (char c : word) {
                if (tempFreq[tolower(c) - 'a'] > 0) {
                    tempFreq[tolower(c) - 'a']--;
                    tempCount--;
                }
                if (tempCount == 0) {
                    if (result.empty() || word.size() < result.size()) {
                        result = word; 
                    }
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string licensePlate = "1s3 PSt";
    vector<string> words = {"step", "steps", "stripe", "stepple"};
    
    string result = sol.shortestCompletingWord(licensePlate, words);
    cout << "The shortest completing word is: " << result << endl;
    
    return 0;
}
