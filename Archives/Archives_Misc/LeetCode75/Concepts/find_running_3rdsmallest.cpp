#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Algorithm:
// Keep updating 1st if you keep finding smaller numbers
// If a greater number than 1st is found, keep updating second and if greater than second found, keep updating 3rd and so on...

int find3rdSmallest(vector<int> &arr) {
    int first = INT_MAX, second = INT_MAX;

    for (int num : arr) {
        if (num <= first) {
            first = num;  // smallest so far
        } else if (num <= second) {
            second = num; // second smallest
        } else {
            return num;   // third number > second ⇒ triplet found
        }
    }

    return -1; 
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 9};

    int result = find3rdSmallest(arr);
    cout << "The 3rd increasing triplet value is: " 
         << (result != -1 ? to_string(result) : "No Result found !") << endl;

    return 0;
}
