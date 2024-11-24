#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int right, int mid) {
    cout << "Merging: Left = " << left << ", Mid = " << mid << ", Right = " << right << endl;
    cout << "Left Array: ";
    for (int i = left; i <= mid; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "Right Array: ";
    for (int i = mid + 1; i <= right; i++) cout << arr[i] << " ";
    cout << endl;

    // Actual merging
    int n1 = mid - left + 1;    // 
    int n2 = right - mid;
    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        cout << "Placing " << arr[k] << " at position " << k << endl;
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        cout << "Copying remaining " << arr[k] << " from Left Array to position " << k << endl;
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        cout << "Copying remaining " << arr[k] << " from Right Array to position " << k << endl;
        j++;
        k++;
    }

    cout << "Merged Array: ";
    for (int i = left; i <= right; i++) cout << arr[i] << " ";
    cout << endl;
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        cout << "Base case reached for left = " << left << ", right = " << right << endl;
        cout<<endl<<endl;
        return;
    }

    int mid = left + (right - left) / 2;
    
    cout<< "split : left: "<<left<<" mid: "<<mid<<endl;
    mergeSort(arr, left, mid);
    cout<< "split : mid: "<<mid+1<<" right: "<<right<<endl;
    mergeSort(arr, mid + 1, right);

    cout<<"Merge : left: "<<left<<" mid: "<<mid<<" right: "<<right<<endl;
    merge(arr, left, right, mid);
}


int main() {
    vector<int> arr = {2, 5, 6, 7, 3, 1, 0};
    int s = 0;
    int e = arr.size() - 1;
    cout << "Initial Array: ";
    for (int i = s; i <= e; i++) cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, s, e);

    cout << "Sorted Array: ";
    for (int i = 0; i <= e; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
