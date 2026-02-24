#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];     // each node can have only 26 children for each next character
    bool isEnd;     // If isEnd is true, it means the word exist and is not just a prefix of any word

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEnd = false;
    }
};

class Trie{
private:
    TrieNode* root;     // Just a pointer

public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;      // Always start iterating from root 
        for(char ch:word){
            int index = ch-'a';
            if(node->children[index]==nullptr){     // if does not exist
                node->children[index] = new TrieNode();     // The index itself represent the existing character
            }
            node = node->children[index];   // Move to next node
        }
        node->isEnd = true;         // This is a word
    }

    bool search(string word){
        TrieNode* node = root;      // Always start iterating from root 
        for(char ch:word){
            int index = ch-'a';
            if(node->children[index]==nullptr){
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix){ // Is there any word with this prefix ?
        TrieNode* node = root;      // Always start iterating from root 
        for(char ch:prefix){
            int index = ch-'a';
            if(node->children[index]==nullptr){
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << "\n";     // true
    cout << trie.search("app") << "\n";       // false
    cout << trie.startsWith("app") << "\n";   // true
    trie.insert("app");
    cout << trie.search("app") << "\n";       // true
}
