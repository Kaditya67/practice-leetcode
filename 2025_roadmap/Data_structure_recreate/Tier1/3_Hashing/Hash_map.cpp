#include <bits/stdc++.h>
using namespace std;

// For custom key hashing (pair hashing)
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2; // XOR for combining
    }
};

int main() {
    // Frequency Count Example
    vector<int> nums = {1, 2, 3, 2, 3, 3, 4};
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    cout << "Frequency Count:\n";
    for (auto& [num, count] : freq) {
        cout << num << " → " << count << "\n";
    }

    // Check Existence
    int target = 2;
    if (freq.count(target)) {
        cout << "\nElement " << target << " exists with freq = " << freq[target] << "\n";
    }

    // Update and Delete
    freq[2] += 5;
    cout << "\nUpdated freq[2] = " << freq[2] << "\n";
    freq.erase(1); // remove key 1
    cout << "After deleting key 1:\n";
    for (auto& [k, v] : freq) cout << k << " → " << v << "\n";

    // Grouping Anagrams
    vector<string> words = {"eat", "tea", "ate", "tan", "nat", "bat"};
    unordered_map<string, vector<string>> anagramGroups;
    for (string word : words) {
        string sorted = word;
        sort(sorted.begin(), sorted.end());
        anagramGroups[sorted].push_back(word);
    }
    cout << "\nAnagram Groups:\n";
    for (auto& [key, group] : anagramGroups) {
        cout << "[";
        for (string& w : group) cout << w << " ";
        cout << "]\n";
    }

    // Custom Key: map<pair<int, int>, int>
    unordered_map<pair<int, int>, int, pair_hash> pairMap;
    pairMap[{1, 2}] = 5;
    pairMap[{2, 3}] = 10;
    cout << "\nCustom pair keys:\n";
    for (auto& [k, v] : pairMap) {
        cout << "(" << k.first << "," << k.second << ") → " << v << "\n";
    }

    return 0;  
}
