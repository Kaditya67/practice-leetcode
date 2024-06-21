#include<iostream>
#include<vector>

using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int totalSatisfaction = 0;

        // Calculate initial satisfaction without using the technique
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                totalSatisfaction += customers[i];
            }
        }

        // Calculate the additional satisfaction we can gain by using the technique
        int maxGain = 0;
        int currentGain = 0;
        
        // Initial window calculation
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                currentGain += customers[i];
            }
        }
        
        maxGain = currentGain;
        
        // Sliding window to find the maximum gain
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 1) {
                currentGain += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                currentGain -= customers[i - minutes];
            }
            maxGain = std::max(maxGain, currentGain);
        }

        return totalSatisfaction + maxGain;
    }
};

int main(){

    Solution s;
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3;
    int result = s.maxSatisfied(customers, grumpy, minutes);
    cout<<result<<endl;
    return 0;
}