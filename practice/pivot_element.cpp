#include<iostream>

using namespace std;


int getPivot(int arr[], int n){
    int start=0;
    int end=n-1;
    int mid=start + (end-start)/2;

    while(start<end){
        if(arr[mid]>arr[start]){
            start=mid+1;        // start is moving ahead
        }
        else{
            end=mid;
        }
        mid=start + (end-start)/2;

    }
    return arr[start];      // return the value at start
}

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"The pivot element is: "<<getPivot(arr, n);
    return 0;
}


// Dry Run
// 7,9,1,2,3

// mid=1
// 1>7     ---> False
// start=7
// end=1

// mid=9
// 9>7     ---> True
// start=1
// end=1
// condition : start<end   ---> false

// return start_value


