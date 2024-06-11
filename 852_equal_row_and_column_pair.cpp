// Brute Force

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// class Solution {
// public:
//     int equalPairs(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int count=0;

//         for(int r=0;r<n;r++){
//             for(int c=0;c<n;c++){
//                 int is_equal=true;
//                 for(int i=0;i<n;i++){
//                     if(grid[r][i]!=grid[i][c]){ // if both values are not equal
//                         is_equal=false;
//                         break;
//                     }
//                 }
//                 if(is_equal){
//                     count++;
//                 }
//             }
//         }
//     }
// };



// optimal approach

// // print proper outputs for understanding only
// #include <iostream>
// #include <vector>
// #include <map>

// using namespace std;

// class Solution {
// public:
//     int equalPairs(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int count = 0;    
//         map<vector<int>, int> mp;

//         // Store each row in the map with its frequency
//         for (int r = 0; r < n; r++) {
//             mp[grid[r]]++;  // Increment the frequency of this row in the map
//             cout << "Row " << r << ": ";
//             for (int num : grid[r]) {
//                 cout << num << " ";
//             }
//             cout << "stored in map. Current map size: " << mp.size() << endl;
//         }

//         cout << "\nStarting column comparison:\n";

//         // Compare each column with the rows stored in the map
//         for (int c = 0; c < n; c++) {
//             vector<int> v;
//             for (int i = 0; i < n; i++) {
//                 v.push_back(grid[i][c]); // Store the column in vector v
//             }

//             cout << "Column " << c << ": ";
//             for (int num : v) {
//                 cout << num << " ";
//             }
//             cout << endl;

//             count += mp[v];   // Add the frequency of this column from the map to count

//             cout << "Count after comparing with column " << c << ": " << count << endl;
//         }
        
//         return count;
//     }
// };

// int main() {
//     vector<vector<int>> grid = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
//     Solution sol;
//     cout << "Total number of equal pairs: " << sol.equalPairs(grid) << endl;

//     return 0;
// }


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;    
        map<vector<int>,int> mp;

        for(int r=0;r<n;r++){
            mp[grid[r]]++;  // r will be incremented and will be stored in map
        }

        cout<<endl<<endl;

        for(int c=0;c<n;c++){
            vector<int> v;
            for(int i=0;i<n;i++){
                v.push_back(grid[i][c]); // c will be stored in vector
            }
            count+=mp[v];   // frequency added
        }
        return count;
    }
};

int main() {
    // grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
    vector<vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    Solution sol;
    cout << sol.equalPairs(grid) << endl;

    return 0;
}