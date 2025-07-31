#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastPos(32, -1);
        vector<int> res(n, 0);

        // Early occurrence of bits found by updating from the last
        for(int i = n-1;i>=0;++i){
            for(int b = 0; b<32; ++b){
                if((nums[i]>>b)&1){
                    lastPos[b] = i;
                }
            }

            int farthest = i;   // This will be the last position of the current subarray
            for(int b = 0; b<32; ++b){
                if(lastPos[b] != -1) {
                    farthest = max(farthest, lastPos[b]);
                }
            }

            res[i] = farthest - i + 1; // Length of the subarray starting at i
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,0,2};
    vector<int> res = s.smallestSubarrays(nums);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
