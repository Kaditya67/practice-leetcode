#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    string word;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEnd = false;
        word = "";
    }
};

class Trie {
private:
    TrieNode* root;

    void dfs(TrieNode* node, vector<string>& suggestions) {
        if (node->isEnd)
            suggestions.push_back(node->word);
        for (int i = 0; i < 26; i++) {
            if (node->children[i])
                dfs(node->children[i], suggestions);
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = tolower(ch) - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
        node->word = word;
    }

    vector<string> getSuggestions(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = tolower(ch) - 'a';
            if (!node->children[idx])
                return {};
            node = node->children[idx];
        }

        vector<string> suggestions;
        dfs(node, suggestions);
        sort(suggestions.begin(), suggestions.end());
        return suggestions;
    }
};

vector<vector<string>> contactSuggestions(vector<string>& contacts, string& query) {
    Trie trie;
    unordered_set<string> uniqueContacts(contacts.begin(), contacts.end());

    for (const string& contact : uniqueContacts)
        trie.insert(contact);

    vector<vector<string>> result;
    string prefix = "";

    for (char ch : query) {
        prefix += ch;
        vector<string> suggestions = trie.getSuggestions(prefix);
        if (suggestions.empty())
            result.push_back({"No suggestions found"});
        else
            result.push_back(suggestions);
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<string> contacts(N);
        for (int i = 0; i < N; i++) {
            cin >> contacts[i];
        }

        string query;
        cin >> query;

        vector<vector<string>> result = contactSuggestions(contacts, query);

        for (const auto& suggestions : result) {
            for (const string& word : suggestions) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

// 1
// 5
// alice bob alicia albert alex
// ali


// Query: "ali"

// Prefix "a":
// Matches: alice, alicia, albert, alex
// "al":
// Still matches: alice, alicia, albert, alex
// "ali":
// Only matches: alice, alicia