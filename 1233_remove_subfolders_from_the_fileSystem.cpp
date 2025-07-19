#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end()); // Lexicographical sort
        vector<string> res;
        int i=0;
        for(const string& f : folder){
            if (res.empty() || f.find(res.back() + "/") != 0) {
                res.push_back(f);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};

    vector<string> result = sol.removeSubfolders(folder);

    cout << "Filtered folders:\n";
    for (const string& f : result) {
        cout << f << endl;
    }

    return 0;
}
