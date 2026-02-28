/**
 * Problem: LeetCode 242 - Valid Anagram
 * CodeChef: CSUB (Count Substrings) - Frequency Logic
 * Atomic Topic: STL Frequency Counting
 *
 * Target Accuracy: 70%+ First-Try
 *
 * Documentation Requirements:
 * 1. Time Complexity: O(N), where N is the length of the string. We traverse
 * each string once.
 * 2. Space Complexity: O(1) as we use a fixed-size integer array of 26 elements
 * for lowercase English letters.
 * 3. Edge Cases Considered:
 *    - Different string lengths (Automatic false)
 *    - All same characters
 *    - Minimum length (1)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length())
      return false;

    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++) {
      freq[s[i] - 'a']++;
      freq[t[i] - 'a']--;
    }

    for (int count : freq) {
      if (count != 0)
        return false;
    }

    return true;
  }
};

int main() {
  Solution sol;
  cout << boolalpha;
  cout << "Test 1 (anagram/nagaram): " << sol.isAnagram("anagram", "nagaram")
       << " (Expected: true)" << endl;
  cout << "Test 2 (rat/car): " << sol.isAnagram("rat", "car")
       << " (Expected: false)" << endl;
  return 0;
}
