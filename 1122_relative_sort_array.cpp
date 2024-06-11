#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        // Step 1: Count the occurrences of each element in arr1
        int h[1001] = {0};
        // This creates a map with entries like:
        // 0:0
        // 1:0
        // 2:0
        // 3:0
        // ..... 1001:0

        // Constraints
        // 1 <= arr1.length, arr2.length <= 1000

        int a = arr1.size(), b = arr2.size();
        for(int i = 0; i < a; i++){
            h[arr1[i]]++;
            cout<<"h["<<arr1[i]<<"] = "<<h[arr1[i]]<<endl;
        }
        
        // cout<<"State of Mp"<<endl;
        // // print the state of mp
        // for(int i = 0; i < 1001; i++){
        //     cout<<"h["<<i<<"] = "<<h[i]<<endl;
        // }

        // Step 2: Place elements of arr2 into arr1 according to their order in arr2
        int j = 0;
        for(int i = 0; i < b; i++){
            while(h[arr2[i]] > 0){
                arr1[j++] = arr2[i];
                h[arr2[i]]--;
            }
        }
        
        // Step 3: Place remaining elements in ascending order
        for(int i = 0; i < 1001; i++){
            while(h[i] > 0){
                arr1[j++] = i;
                h[i]--;
            }
        }
        return arr1;
    }
};

int main() {
    // Input vectors
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};

    // Solution object
    Solution solution;

    cout<<"arr1 = {2,3,1,3,2,4,6,7,9,2,19} and arr2 = {2,1,4,3,9,6}"<<endl;
    // Getting the result after relative sorting
    vector<int> result = solution.relativeSortArray(arr1, arr2);

    // Printing the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
