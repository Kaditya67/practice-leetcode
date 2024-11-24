/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        int result = 0;
        for (const auto& box : boxTypes) {
            int boxCount = box[0];
            int unitsPerBox = box[1];

            if (truckSize >= boxCount) {
                result += boxCount * unitsPerBox;
                truckSize -= boxCount;
            } else { 
                result += truckSize * unitsPerBox;
                break;
            }
        }
        return result;
    }
};

// @lc code=end

