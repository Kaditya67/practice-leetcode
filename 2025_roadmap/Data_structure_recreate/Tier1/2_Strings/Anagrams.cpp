#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Anagram: "Same characters in the same frequency"
bool isAnagram_sort(string s, string t) {
    if (s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

bool isAnagram_map(string s, string t) {
    if (s.length() != t.length()) return false;

    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    for (int count : freq)
        if (count != 0) return false;

    return true;
}

int main(){
    string s = "listen";
    string t = "silent";
    cout<<"Word1 : "<<s<<endl;
    cout<<"Word2 : "<<t<<endl;

    bool res1  = isAnagram_map(s,t);
    cout<<"Map Says : "<<((res1==1)?"It is a Anagram":"It is not a Anagram")<<endl;
    bool res2 = isAnagram_sort(s,t);
    cout<<"Sorting Says : "<<((res2==1)?"It is a Anagram":"It is not a Anagram")<<endl;
}
