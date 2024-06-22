#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int Oddcount = 0;
        int result = 0;
        int n = nums.size();
        mp[Oddcount] = 1;

        for(int i = 0; i < n; i++){
            Oddcount+=(nums[i]%2);

            if(mp.count(Oddcount-k)){
                result+=mp[Oddcount-k];
            }

            mp[Oddcount]++;
        }
        return result;
    }
};

int main(){

    vector<int> nums = {1,1,2,1,1};
    int k = 3;

    Solution sol;

    cout<<sol.numberOfSubarrays(nums, k);

    return 0;
}