#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        const int MOD = 1000000007;
        int n=nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }

        int result=1;
        int i=0;
        int j=0;
        j=max(j,mp[nums[0]]);
        while(i<n){
            if(i>j){
                result=(result*2)%MOD;
            }
            j=max(j,mp[nums[i]]);
            i++;
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 4, 5}; // Example input array
    int count = sol.numberOfGoodPartitions(nums);
    std::cout << "Number of good partitions: " << count << std::endl;
    return 0;
}
