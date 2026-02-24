#include<iostream>
#include<vector>
using namespace std;

void printSubarray(vector<int> &arr, int k){
    // All Subarrays
    int l=0,r=0;
    int n = arr.size();
    if(n<k){
        cout<<"Invalid Window Size";
        return;
    }

    for(int i=0;i<n-k;i++){
        cout<< "[ ";
       for(int j=0;j<k;j++){
           cout<<arr[i+j]<<" ";
       }
       cout<< "]"<<endl;
    }

}
int main(){
    vector<int> arr ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int k = 5;
    printSubarray(arr,k);
    return 0;
}
