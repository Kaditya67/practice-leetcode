#include <iostream>
#include <vector>
#include <string>
#include <cstring> // Include cstring for memset
#include <sstream> // Include sstream for stringstream

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        memset(children, 0, sizeof(children));
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root;

    Solution() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }

    string checkWord(const string& word) {
        TrieNode* curr = root;
        string prefix;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                return word;
            }
            prefix += c;
            curr = curr->children[c - 'a'];
            if (curr->isEnd) {
                return prefix;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, const string& sentence) {
        for (const string& word : dictionary) {
            insert(word);
        }

        stringstream s(sentence);
        string word, ans;
        while (s >> word) {
            if (!ans.empty()) {
                ans += " ";
            }
            ans += checkWord(word);
        }

        return ans;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    string result = solution.replaceWords(dictionary, sentence);
    cout << result << endl; // Output: "the cat was rat by the bat"
    return 0;
}
