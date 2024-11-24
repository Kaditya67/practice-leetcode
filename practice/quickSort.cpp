#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high]; 
        int i = low - 1; 
        cout << "Low: " << low << ", High: " << high << endl;
        cout << "Pivot: " << pivot << endl;

        for (int j = low; j <= high - 1; j++) {
            cout << "j: " << j << ", Arr[j]: " << arr[j] << endl;
            if (arr[j] <= pivot) {
                i++;
                cout << "Swap: " << arr[i] << " and " << arr[j] << endl;
                swap(arr[i], arr[j]);
            }
        }
        cout << "Final Swap: " << arr[i + 1] << " and " << arr[high] << endl;
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        // Recursive calls
        cout << "Left Partition: low=" << low << ", high=" << pi - 1 << endl;
        quickSort(arr, low, pi - 1);
        cout << "Right Partition: low=" << pi + 1 << ", high=" << high << endl;
        quickSort(arr, pi + 1, high);
    } else {
        cout << "No sorting needed for low=" << low << " and high=" << high << endl;
    }
}

int main() {
    vector<int> arr = {20,30,14,56,9,72,45,5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
