// Problem: https://leetcode.com/problems/implement-trie-prefix-tree/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class TrieNode{ 
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        isEnd =  false;
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root; // Declare
public:
    Trie() {
        root = new TrieNode();     // Initialize
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char ch:word){
            int idx = ch-'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch:word){
            int idx = ch-'a';
            if(!node->children[idx]){
                return false;
            }
            node = node->children[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch:prefix){
            int idx = ch-'a';
            if(!node->children[idx]){
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << "\n";   // returns true
    cout << trie->search("app") << "\n";     // returns false
    cout << trie->startsWith("app") << "\n"; // returns true
    trie->insert("app");
    cout << trie->search("app") << "\n";     // returns true
    return 0;
}
