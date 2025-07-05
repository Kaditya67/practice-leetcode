#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target){
    int l = 0;
    int h = arr.size()-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid]>target){
            h=mid-1;
        }else if(arr[mid]<target){
            l=mid+1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){

    vector<int> productIDs = {101, 205, 333, 404, 555, 660, 777};
    int targetID = 555;

    int idx = binarySearch(productIDs, targetID);
    if (idx != -1)
        cout << "Product found at index " << idx<<endl;
    else
        cout << "Product not found!"<<endl;

    return 0;
}
