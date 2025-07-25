// Problem: https://leetcode.com/problems/search-suggestions-system/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    vector<string> suggestions;

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();

            node = node->children[idx]; 
            if (node->suggestions.size() < 3)
                node->suggestions.push_back(word);
        }
    }

    vector<vector<string>> getSuggestions(string& word) {
        TrieNode* node = root;
        vector<vector<string>> result;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node && node->children[idx]) {
                node = node->children[idx];
                result.push_back(node->suggestions);
            } else {
                while (result.size() < word.size())
                    result.push_back({});
                break;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());  
        Trie trie;

        for (string& product : products) {
            trie.insert(product);
        }
 
        return trie.getSuggestions(searchWord);
    }
};

int main() {
    Solution s;
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";
    vector<vector<string>> result = s.suggestedProducts(products, searchWord);
    for (auto& v : result) {
        for (auto& str : v)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}
