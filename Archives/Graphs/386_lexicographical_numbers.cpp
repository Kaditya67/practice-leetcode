#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<int> result;
//         int current = 1;

//         for (int i = 0; i < n; ++i) {
//             result.push_back(current);

//             if (current * 10 <= n) {
//                 // Move to the next lexicographical level (10x)
//                 current *= 10;
//             } else {
//                 // Increment current if possible
//                 while (current % 10 == 9 || current + 1 > n) {
//                     // Move up if current ends with 9 or cannot increment without exceeding n
//                     current /= 10;
//                 }
//                 current += 1;
//             }
//         }

//         return result;
//     }
// };


vector<int> lexicalOrder(int n) {
    vector<int> result;
    int current = 1;

    for (int i = 0; i < n; ++i) {
        result.push_back(current);

        if (current * 10 <= n) {
            // Go deeper (like multiplying by 10)
            current *= 10;
        } else {
            // Try to increment the current number
            if (current % 10 != 9 && current + 1 <= n) {
                current += 1;
            } else {
                // Move up by dividing by 10 until we can increment
                while (current % 10 == 9) {
                    current /= 10;
                }
                current += 1;
            }
        }
    }

    return result;
}

int main() {
    int n = 13;  // Example input
    vector<int> lexNumbers = lexicalOrder(n);

    // Print the result
    for (int num : lexNumbers) {
        cout << num << " ";
    }
    return 0;
}
