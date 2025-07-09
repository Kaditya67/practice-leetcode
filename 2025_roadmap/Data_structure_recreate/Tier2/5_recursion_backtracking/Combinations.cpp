#include<bits/stdc++.h>
using namespace std;

void combineUtil(int start, int n, int k, vector<int>& curr, vector<vector<int>>& result) {
    if (curr.size() == k) {
        result.push_back(curr);
        return;
    }
    for (int i = start; i <= n; i++) {
        curr.push_back(i);
        combineUtil(i + 1, n, k, curr, result);
        curr.pop_back();  // backtrack
    }
}

int main() {
    int n = 4, k = 2;
    vector<int> curr;
    vector<vector<int>> result;

    combineUtil(1, n, k, curr, result);

    for (auto& comb : result) {
        for (int x : comb) cout << x << " ";
        cout << "\n";
    }
}
