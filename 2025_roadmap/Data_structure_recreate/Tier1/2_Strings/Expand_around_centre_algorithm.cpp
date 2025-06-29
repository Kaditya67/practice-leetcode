#include <iostream>
#include <string>
using namespace std;

// Expand Around Centre
string longestPalindromicSubsequence(string s){
    string res;
    // 1. Generate Subsequences
    // 2. Use as centre and check for longest palindrome for Odd length
    // 3. Use as centre along with neighbour and check for longest palindrome for even length
    // Keep Updating the MaxVarible
    int n = s.length();
    int maxLen=0;
    int start = 0;
    for(int i=0;i<n-1;i++){
        // Odd Length Palindrome
        int j = i,k = i;
        while(j>=0 && k<n && s[j]==s[k]){
            if(k-j+1 > maxLen){
                maxLen = k-j+1;
                start = j;
            }
            j--;
            k++;
        }

        // Even Length Palindrome
        j = i,k = i+1;
        while(j>=0 && k<n && s[j]==s[k]){
            if(k-j+1 > maxLen){
                maxLen = k-j+1;
                start = j;
            }
            j--;
            k++;
        }
        res = s.substr(start,maxLen);
    }
    return res;
}

int main(){
    string s = "babad";
    string res = longestPalindromicSubsequence(s);
    cout<<"Longest Palindromic Subsequnce is : "<<res<<endl;
    return 0;
}
