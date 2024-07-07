#include<iostream>

using namespace std;

bool isSorted(int *arr,int n){

    if(n==0 || n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }else{
        return isSorted(arr+1,n-1);
    }
}

int main(){

    int arr[5]={1,2,3,6,5};
    int n=5;

    bool ans=isSorted(arr,n);

    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    return 0;
}

// For Vector

// #include <iostream>
// #include <vector>

// using namespace std;

// bool isSorted(const vector<int>& vec, int n) {
//     if (n == 0 || n == 1) {
//         return true;
//     }
//     if (vec[0] > vec[1]) {
//         return false;
//     } else {
//         vector<int> subVec(vec.begin() + 1, vec.end());
//         return isSorted(subVec, n - 1);
//     }
// }

// int main() {
//     vector<int> vec = {1, 2, 3, 6, 5};
//     int n = vec.size();

//     bool ans = isSorted(vec, n);

//     if (ans) {
//         cout << "Array is sorted" << endl;
//     } else {
//         cout << "Array is not sorted" << endl;
//     }

//     return 0;
// }
