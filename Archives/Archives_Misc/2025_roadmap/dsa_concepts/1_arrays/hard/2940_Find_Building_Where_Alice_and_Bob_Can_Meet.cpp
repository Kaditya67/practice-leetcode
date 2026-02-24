#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findClosestTallerBuilding(vector<int> &heights, vector<int> &nextTallerBuilding, vector<int> &rightSortedLimit, int height, int startIndex) {
        int numBuildings = heights.size();
        if (startIndex >= numBuildings || startIndex == -1) return -1;
        if (heights[startIndex] > height) return startIndex;
        if (nextTallerBuilding[startIndex] == -1) return -1;
        if (heights[rightSortedLimit[startIndex]] <= height) 
            return findClosestTallerBuilding(heights, nextTallerBuilding, rightSortedLimit, height, nextTallerBuilding[rightSortedLimit[startIndex]]);
        int left = startIndex, right = rightSortedLimit[startIndex];
        int closestTallerBuildingIndex = heights[nextTallerBuilding[startIndex]];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (heights[mid] <= height) {
                closestTallerBuildingIndex = max(closestTallerBuildingIndex, mid);
                left = mid + 1;
            } else {
                closestTallerBuildingIndex = mid;
                right = mid - 1;
            }
        }
        return findClosestTallerBuilding(heights, nextTallerBuilding, rightSortedLimit, height, closestTallerBuildingIndex);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int numBuildings = heights.size(), numQueries = queries.size();
        vector<int> nextTallerBuilding(numBuildings, -1);
        vector<int> rightSortedLimit(numBuildings, numBuildings - 1);
        for (int i = numBuildings - 2; i >= 0; --i) {
            rightSortedLimit[i] = heights[i + 1] >= heights[i] ? rightSortedLimit[i + 1] : i;
            nextTallerBuilding[i] = findClosestTallerBuilding(heights, nextTallerBuilding, rightSortedLimit, heights[i], i + 1);
        }
        vector<int> meetingPoint(numQueries, -1);
        for (int i = 0; i < numQueries; ++i) {
            int aliceIndex = queries[i][0];
            int bobIndex = queries[i][1];
            if (aliceIndex > bobIndex) swap(aliceIndex, bobIndex);
            if (aliceIndex == bobIndex) {
                meetingPoint[i] = aliceIndex;
            } else if (heights[bobIndex] > heights[aliceIndex]) {
                meetingPoint[i] = bobIndex;
            } else if (nextTallerBuilding[aliceIndex] == -1 || nextTallerBuilding[bobIndex] == -1) {
                meetingPoint[i] = -1;
            } else {
                int maxHeight = max(heights[aliceIndex], heights[bobIndex]);
                int startIndex = max(nextTallerBuilding[aliceIndex], nextTallerBuilding[bobIndex]);
                meetingPoint[i] = findClosestTallerBuilding(heights, nextTallerBuilding, rightSortedLimit, maxHeight, startIndex);
            }
        }
        return meetingPoint;
    }
};


int main() {

    // case 1 - [2,5,-1,5,2]
    vector<int> heights = {6,4,8,5,2,7};
    vector<vector<int>> queries = {{0, 1}, {0,3}, {2,4}, {3,4}, {2,2}};
    Solution sol;
    vector<int> result = sol.leftmostBuildingQueries(heights, queries);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // case 2 - [7,6,-1,4,6]
    heights = {5,3,8,2,6,1,4,6};
    queries = {{0,7}, {3,5}, {5,2}, {3,0}, {1,6} };
    result = sol.leftmostBuildingQueries(heights, queries);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // case 3 - 
    heights = {1,2,1,2,1,2};
    queries = {{0,0},{0,1},{0,2},{1,1}};
    result = sol.leftmostBuildingQueries(heights, queries);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}