#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr,int left, int right,int mid){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0; 
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);

    merge(arr,left,right,mid);
}

int main() {
    vector<int> arr = {2, 5, 6, 7, 3, 1, 0};
    int s = 0;
    int e = arr.size() - 1;
    mergeSort(arr, s, e);

    for (int i = 0; i <= e; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
