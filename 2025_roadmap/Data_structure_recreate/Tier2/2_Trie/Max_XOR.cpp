#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[2]; // only 0 and 1

    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int getMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opp = 1 - bit;

            if (node->children[opp]) {
                maxXOR |= (1 << i); // take the opposite bit to maximize XOR
                node = node->children[opp];
            } else {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    Trie trie;
    
    // Insert all elements from arr2 into the Trie
    for (int num : arr2) {
        trie.insert(num);
    }

    int maxResult = 0;
    for (int num : arr1) {
        maxResult = max(maxResult, trie.getMaxXOR(num));
    }

    return maxResult;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr1(n), arr2(m);
        for (int i = 0; i < n; i++) cin >> arr1[i];
        for (int i = 0; i < m; i++) cin >> arr2[i];

        cout << maxXOR(n, m, arr1, arr2) << endl;
    }
    return 0;
}

// T = 1
// arr1 = [6, 6, 0, 6, 8, 5, 6]
// arr2 = [1, 7, 1, 7, 8, 0, 2]

