#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<float>& arr, int n) {
    for (int i = 1; i < n; ++i) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; ++i) {
        int index = arr[i] * n; // for arr[i] ∈ [0, 1)
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        insertionSort(buckets[i], buckets[i].size());
    }

    int idx = 0;
    for (int i = 0; i < n; ++i) {
        for (float val : buckets[i]) {
            arr[idx++] = val;
        }
    }
}

//! Tune to work for MinValue and MaxValue range
// int n = arr.size();
// int minVal = *min_element(arr.begin(), arr.end());
// int maxVal = *max_element(arr.begin(), arr.end());

// int bucketSize = 10;  // You can tune this
// int bucketCount = (maxVal - minVal) / bucketSize + 1;

// vector<vector<int>> buckets(bucketCount);

// // Distribute values into buckets
// for (int num : arr) {
//     int index = (num - minVal) / bucketSize;
//     buckets[index].push_back(num);
// }


void printArray(const vector<float>& arr) {
    for (float val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};

    cout << "Original array: ";
    printArray(arr);

    bucketSort(arr);

    cout << "Sorted array (Bucket Sort): ";
    printArray(arr);

    return 0;
}
