#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s){
    int n = s.length();
    int l=0;
    int r = n-1;
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main(){
    string s = "bab";
    bool res = isPalindrome(s);
    cout<<s<<" Sequence is Palindrome: "<<res<<endl;
    return 0;
}
