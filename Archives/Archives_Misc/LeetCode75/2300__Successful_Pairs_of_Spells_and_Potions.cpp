// Problem: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        int m = spells.size();
        sort(potions.begin(), potions.end());
        vector<int> res(m);

        for (int i = 0; i < m; ++i) {
            int l = 0, r = n;
 
            while (l < r) {
                int mid = l + (r - l) / 2;
                if ((long long)spells[i] * potions[mid] >= success)
                    r = mid;
                else
                    l = mid + 1;
            }

            res[i] = n - l;
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> spells = {5,1,3}, potions = {1,2,3,4,5};
    long long success = 7;
    vector<int> res = s.successfulPairs(spells, potions, success);
    for (int i : res) cout << i << " "; cout << endl;
    return 0;
}
