#include<iostream>
using namespace std;

bool linearSearch(int *arr, int n, int key){
    if(n==0){
        return false;
    }

    if(arr[0]==key){
        return true;
    }else{
        return linearSearch(arr+1,n-1,key);
    }
}
int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int n=10;
    int key=11;

    bool ans = linearSearch(arr, n, key);
    if(ans){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
    return 0;
}