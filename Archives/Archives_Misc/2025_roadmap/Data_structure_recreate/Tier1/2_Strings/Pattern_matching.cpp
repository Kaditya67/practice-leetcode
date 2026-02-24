// pattern	        s	        Output
// "abba"	"dog cat cat dog"	✅ true          {a->dog,b->cat}
// "abba"	"dog cat cat fish"	❌ false
// "aaaa"	"dog dog dog dog"	✅ true
// "abba"	"dog dog dog dog"	❌ false

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

// single map issues:
// Your single map will say:
// a → dog ✅
// b → dog ✅ (because b wasn’t seen before, so it sets b → dog — wrong!)

bool patternMatch(string pattern, string s){
    stringstream ss(s);
    string word;
    vector<string> words;

    // while (ss >> word)
    while (getline(ss, word, ' ')) {
        words.push_back(word);
    }

    int n = pattern.length();
    if(n!=words.size()) return false;

    unordered_map<char, string> p2w; // pattern -> word
    unordered_map<string, char> w2p; // word -> pattern

    for (int i = 0; i < pattern.length(); i++) {
        char p = pattern[i];
        string w = words[i];

        // If exists, check for correct mapping
        if (p2w.count(p) && p2w[p] != w) return false;
        if (w2p.count(w) && w2p[w] != p) return false;

        // Assign
        p2w[p] = w;
        w2p[w] = p;
    }
    return true;
}

// Bijective (1:1) mapping
int main(){
    string pattern = "abba";
    string s = "dog cat cat fish";

    bool res = patternMatch(pattern,s);
    cout<<((res==1) ? "Pattern Match" : "Pattern Does not Match")<<endl;
    return 0;
}
