// Sort by each digit (starting from least significant to most significant) using Stable Counting Sort.
// Input:
// [170, 45, 75, 90, 802, 24, 2, 66]

// Sort by:
// 1s place → [170, 90, 802, 2, 24, 45, 75, 66]
// 10s place → [802, 2, 24, 45, 66, 170, 75, 90]
// 100s place → [2, 24, 45, 66, 75, 90, 170, 802] ✅ Sorted!

#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr, int n,int place) {
    vector<int> count(10,0);   // Count array for digits 0-9
    
    for(int num:arr){          
        count[(num/place)%10]++;        // For the chosen place, count the frequency of digits
    }

    // Do the cumulative sum of count array to find the correct position to place the element,
    // if 1st element is stored till 2 and if my count is 2 then i will be there at previous_element_count+1,previous_element_count+2
    for(int i=1;i<10;i++){          
        count[i] += count[i-1];         // Cumulative sum
    }

    vector<int> output(n);
    // In stable sort, if two elements have the same key (i.e., same digit), the one that appears earlier in the original array should appear earlier in the sorted result.
    for(int i=n-1;i>=0;i--){
        int digit = (arr[i]/place)%10;      // 1001/10 = 100.1, 100.1%10 = 0
        output[--count[digit]] = arr[i];    // Get the count of that digit and place it there
    }

    arr = output;
}

void radixSort(vector<int> &arr) {
    int n = arr.size();
    int maxElement = *max_element(arr.begin(), arr.end());   // Use it to decide the number of digits
    for(int place=1; maxElement/place > 0; place *= 10){     // Increase the place until we get in points
        countingSort(arr, n, place);                            // Sort by each digit
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main(){
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    printArray(arr);

    radixSort(arr);

    cout << "Sorted array (Radix Sort): ";
    printArray(arr);

    return 0;
}