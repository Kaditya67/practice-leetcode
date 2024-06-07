#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            ans = mid;
            high = mid - 1;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int lastOcc(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;  // This may exceed the int limit range, Instead use this -->       // low + (high - low)/2
        if (arr[mid] == key) {
            ans = mid;
            low = mid + 1;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;

    cout << "Enter the key to find the index of its first occurrence: ";
    cin >> key;

    int first = firstOcc(arr, n, key);
    if (first != -1) {
        cout << "The index of the first occurrence of the key is: " << first << endl;
    } else {
        cout << "The key is not present in the array." << endl;
    }

    int last = lastOcc(arr, n, key);
    if (last != -1) {
        cout << "The index of the last occurrence of the key is: " << last << endl;
    } else {
        cout << "The key is not present in the array." << endl;
    }

    return 0;
}
