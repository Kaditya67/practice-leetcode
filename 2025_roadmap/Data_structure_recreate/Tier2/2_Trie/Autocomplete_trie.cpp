#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> freqMap;
    TrieNode() {}
};

class AutocompleteSystem {
private:
    TrieNode* root;
    string currInput;
    TrieNode* currNode;

    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second; // lex smaller first
            return a.first < b.first;       // higher freq first
        }
    };

    void insert(string sentence, int freq) {
        TrieNode* node = root;
        for (char c : sentence) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
            node->freqMap[sentence] += freq;
        }
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        currNode = root;
        currInput = "";

        for (int i = 0; i < sentences.size(); i++) {
            insert(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            insert(currInput, 1);
            currInput = "";
            currNode = root;
            return {};
        }

        currInput += c;

        if (!currNode || !currNode->children.count(c)) {
            currNode = nullptr;
            return {};
        }

        currNode = currNode->children[c];
        auto& freqMap = currNode->freqMap;

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for (auto& [sentence, freq] : freqMap) {
            pq.push({freq, sentence});
            if (pq.size() > 3)
                pq.pop(); // maintain top 3
        }

        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        reverse(result.begin(), result.end()); // since min-heap
        return result;
    }
};

int main() {
    vector<string> sentences = {"i love you", "island", "ironman", "i love leetcode"};
    vector<int> times = {5, 3, 2, 2};

    AutocompleteSystem acSystem(sentences, times);

    vector<char> inputs = {'i', ' ', 'l', 'o', '#', 'i', ' '};
    for (char c : inputs) {
        vector<string> suggestions = acSystem.input(c);
        if (c != '#') {
            cout << "Input: '" << c << "' -> Suggestions: ";
            for (const string& s : suggestions) {
                cout << "\"" << s << "\" ";
            }
            cout << endl;
        }
    }

    return 0;
}

// 'i':

// Matching nodes:
// "i love you" (5)
// "i love leetcode" (2)
// "island" (3)
// "ironman" (2)

// Top 3: i love you, island, i love leetcode