#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq; // min-heap based on frequency
    }
};

void buildCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->ch] = code; // leaf node, assign code
    }
    buildCodes(root->left, code + "0", codes);
    buildCodes(root->right, code + "1", codes);
}

unordered_map<char, string> huffmanEncoding(vector<pair<char, int>>& freqs) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (auto& p : freqs) {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    unordered_map<char, string> codes;
    buildCodes(pq.top(), "", codes);
    return codes;
}

int main() {
    // Sample frequency table for characters
    vector<pair<char, int>> freqs = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}
    };

    unordered_map<char, string> codes = huffmanEncoding(freqs);

    cout << "Huffman Codes:\n";
    for (auto& [ch, code] : codes) {
        cout << ch << " -> " << code << "\n";
    }

    return 0;
}
