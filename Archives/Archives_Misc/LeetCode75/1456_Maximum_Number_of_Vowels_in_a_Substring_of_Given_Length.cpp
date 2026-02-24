// Problem: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Difficulty: Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }

    int maxVowels(string s, int k) {
        int j=0;
        int res = 0;
        int n = s.length();
        while(j<k){
            if(isVowel(s[j])) res++;
            j++;
        }

        int i=0;
        int maxCount = res;

        while(j<n){
            if(isVowel(s[i++])) res--;
            if(isVowel(s[j++])) res++;
            maxCount = max(maxCount,res);
        }
        return maxCount;
    }
};

int main() {
    Solution s;
    string str = "leetcode";
    int k = 3;
    cout << s.maxVowels(str, k) << endl; // Example usage
    return 0;
}

