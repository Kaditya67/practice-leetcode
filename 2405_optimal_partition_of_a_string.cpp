#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int n=s.length();
        vector<int>last_seen(26,-1);
        int ans=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            if(last_seen[s[i]-'a']>=start)
            {
                ans++;
                start=i;
            }
            last_seen[s[i]-'a']=i;
        }
        return ans+1;
    }
};

int main(){

    string s="abacaba";
    Solution obj;
    cout<<obj.partitionString(s);
    return 0;
}