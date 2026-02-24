#include<iostream>
#include<vector>
using namespace std;

// LeftSum
vector<int> PrefixSum(vector<int> &arr){
    int n = arr.size();
    vector<int> prefix(n);
    int temp = 0;
    for(int i=0;i<n;i++){
        prefix[i]=temp;
        temp += arr[i];
    }
    return prefix;
}

vector<int> RightSum(vector<int> &arr){
    int n = arr.size();
    vector<int> rSum(n);
    int temp=0;
    for(int i=n-1;i>=0;i--){
        rSum[i]=temp;
        temp += arr[i];
    }
    return rSum;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    vector<int> lSum = PrefixSum(arr);
    vector<int> rSum = RightSum(arr);
    cout<<"Left Sum : ";
    for(int val:lSum){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"Right Sum : ";
    for(int val:rSum){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
