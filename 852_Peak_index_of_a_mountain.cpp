#include<iostream>
#include<vector>

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;

        int mid=low+(high-low)/2;

        while(low<high){
            mid=low+(high-low)/2;
            if(arr[mid]<arr[mid+1]){
                low=mid+1;
            }
            else{
                high=mid;
            }

        }
        return low;
    }
};