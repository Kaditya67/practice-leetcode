#include <iostream>

using namespace std;

void swap(int *a, int *b){
    // addresses are swapped here
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        // bubble sort from 1 to n-1
        bool swapped = false;
        for(int j = 0; j < n - i; j++){
            if(arr[j] > arr[j + 1]){
                // cout << "Before swap: " << endl;
                // cout << "arr[" << j << "] : " << arr[j] << "  arr[" << j + 1 << "] : " << arr[j + 1] << endl;
                swap(&arr[j], &arr[j + 1]);
                // cout << "After swap: " << endl;
                // cout << "arr[" << j << "] : " << arr[j] << "  arr[" << j + 1 << "] : " << arr[j + 1] << endl;
                swapped = true;  // set swapped to true if a swap occurs
            }
        }
        if(!swapped){   // If elements are already sorted then break
            break;
        }
    }
}


// Dry Run
// 1,2,4,3,5

// 1st iteration:

// swapped=false        --------------------
// 1<2-->no swap
// 2<4-->no swap 
// 4>3-->swap            ---> swapped=true
// 1,2,3,4,5
// 4<5-->no swap

// 2nd iteration

// swapped = false  -------------------
// 1<2-->no swap
// 2<3-->no swap
// 3<4-->no swap
// 4<5-->no swap

// swapped = false         ----> break
// This is optimised bubble sort


int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    bubble_sort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
