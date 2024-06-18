#include<iostream>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(0);
        int l=0,r=s.length()-1;
        while(l<r &&s[l]==s[r]){
            char ch=s[l];
            while(l<=r&&s[l]==ch)l++;
            while(l<=r&&s[r]==ch)r--;
        }
         return r-l+1;
    }
};

int main(){
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.minimumLength(s); 
    return 0;
}