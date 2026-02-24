// Problem: https://leetcode.com/problems/koko-eating-bananas/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canEatAll(vector<int>&piles,int mid,int h){
        int actualHours = 0;
        for(int &x:piles){
            actualHours+=x/mid;

            if(x%mid!=0){   // one extra for remaining bananas
                actualHours++;
            }
        }
        return actualHours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());

        while(left<right){
            int mid = left+(right-left)/2;
            if(canEatAll(piles,mid,h)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};

int main() {
    Solution s;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << s.minEatingSpeed(piles, h) << endl;
    return 0;
}

