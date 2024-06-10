#include <iostream>
    
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {   // For 1st to last number
        int key = arr[i];       // Choose a number to place all numbers in the right place  // 1st number
        // cout<<"key: "<<key<<endl;
        int j = i - 1;  // check for previous number
        
        // cout<<"arr[j]>key: "<<(arr[j]>key)<<endl;
        while (j >= 0 && arr[j] > key) {    // check for condition
            arr[j + 1] = arr[j];
            // cout<<"Shifted arr[j+1]: "<<arr[j+1]<<endl;
            // cout<<"arr[j]: "<<arr[j]<<endl;
            // cout<<"arr[j+1]: "<<arr[j+1]<<endl;
            j--;
        }
        arr[j + 1] = key;   // place the number in the right place
        // cout<<"arr[j+1]: "<<arr[j+1]<<endl;
        cout<<endl<<endl;
    }
}

// Dry run

// 7,9,1,2,3
//  1st Iteration : 
//  key = 9
//  j = 0
//  arr[0] > key    // 7>9  --> false 
//  arr[1] = 9

//  2nd Iteration :     7,9,1,2,3
//  key = 1
//  j = 1
//  arr[1] > key    // 9>1  --> true
//  arr[2] = 9      // shift

// arr[0] > key    // 7>1  --> true
// arr[1] = 7       // shift        // j+1 = 1

// j-- = -1
// arr[0] = 1   // j+1 = 0

// 3rd Iteration :     1,7,9   |   2,3
// ..... so on

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertion_sort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}