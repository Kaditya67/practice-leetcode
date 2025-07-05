#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int rotatedBinarySearch(vector<int> &arr, int target){
    int l = 0;
    int h = arr.size() - 1;
    
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == target) return mid;

        // Left half is sorted
        if (arr[l] <= arr[mid]) {
            if (arr[l] <= target && target < arr[mid]) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (arr[mid] < target && target <= arr[h]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
    }

    return -1;
}

int main(){

    vector<int> productIDs = {8,9,10,12,16,1,2,3,4,5,6,7};
    int targetID = 10;

    int idx = rotatedBinarySearch(productIDs, targetID);
    if (idx != -1)
        cout << "Product found at index " << idx<<endl;
    else
        cout << "Product not found!"<<endl;

    return 0;
}
