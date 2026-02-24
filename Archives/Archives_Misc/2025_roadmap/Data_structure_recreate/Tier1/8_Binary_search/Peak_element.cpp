#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // If mid element is less than next → peak lies to the right
        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } else {
            // Peak lies to the left (including mid)
            high = mid;
        }
    }

    return low; // or return high; both are same when loop exits
}

int main(){

    vector<int> productIDs = {101, 205, 400, 700, 555, 200, 150};

    int idx = findPeak(productIDs);
    if (idx != -1)
        cout << "Product found at index " << idx<<endl;
    else
        cout << "Product not found!"<<endl;

    return 0;
}
