#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // store the biggest index for each character
        int n = s.size();
        vector<int> counter(26, -1);
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            counter[s[i] - 'a'] = max(counter[s[i] - 'a'], i);
        }

        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, counter[s[i] - 'a']);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};

int main(){

    string s = "ababcbacadefegdehijhklij";
    Solution obj;
    vector<int> result = obj.partitionLabels(s);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}