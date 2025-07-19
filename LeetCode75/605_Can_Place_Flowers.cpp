// Problem: https://leetcode.com/problems/can-place-flowers/
// Difficulty: Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        for (int i = 0; i < N && n > 0; i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == N - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                n--;
                i++; // Jump Extra +1 to avoid repeatative checking // To not Plant at Adjacent Position
            }
        }
        return n == 0;
    }
};


int main() {
    Solution s;
    vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;
    cout << s.canPlaceFlowers(flowerbed,n) << endl;
    return 0;
}


