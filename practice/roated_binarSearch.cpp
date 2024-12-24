#include <iostream>
#include <vector>
using namespace std;


void printArr(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int getPivot(vector<int>& arr, int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e) {
        cout<<"Start is : "<<s<<" mid is : "<<arr[mid]<<endl;
        if (arr[mid] >= arr[0]) {
            printArr(arr,n);
            s = mid + 1;
        } else {
            cout<<"End is : "<<e<<endl;
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    cout<<"Start at : "<<s<<" and Number is : "<<arr[s]<<endl;
    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;

    while (start <= end) {
        if (arr[mid] == key) {
            return mid;
        }
        if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int findPosition(vector<int>& arr, int n, int k) {
    int pivot = getPivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1]) {
        return binarySearch(arr, pivot, n - 1, k);
    } else {
        return binarySearch(arr, 0, pivot - 1, k);
    }
}


int main() {
    vector<int> arr = {7, 9,10,12,15,18,20, 1, 2, 3,4,5};
    int key = 2;
    int n = arr.size();
    int position = findPosition(arr, n, key);
    cout << "Position of " << key << " is: " << position << endl;
    return 0;
}
