// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// class Solution {
// private:
//     void swap(int *a, int *b) {
//         int temp = *a;
//         *a = *b;
//         *b = temp;
//     }

//     void bubble_sort(vector<int>& arr, vector<int>& profits, int n) {
//         for (int i = 1; i < n; i++) {
//             bool swapped = false;
//             for (int j = 0; j < n - i; j++) {
//                 if (arr[j] > arr[j + 1]) {
//                     swap(&arr[j], &arr[j + 1]);
//                     swap(&profits[j], &profits[j + 1]);
//                     swapped = true;
//                 }
//             }
//             if (!swapped) {
//                 break;
//             }
//         }
//     }

// public:
//     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
//         int n = profits.size();
//         // Sort capital and move elements of profit similarly
//         bubble_sort(capital, profits, n);

//         priority_queue<int> maxHeap;
//         int i = 0;

//         while (k > 0) {
//             // Push all affordable projects to the max-heap
//             while (i < n && capital[i] <= w) {
//                 maxHeap.push(profits[i]);
//                 i++;
//             }

//             // If there are no affordable projects, break
//             if (maxHeap.empty()) {
//                 break;
//             }

//             // Select the most profitable project
//             w += maxHeap.top();
//             maxHeap.pop();
//             k--;
//         }
//         return w;
//     }
// };

// int main() {
//     Solution s;
//     int k = 3;
//     int w = 0;
//     vector<int> profits = {1, 2, 3};
//     vector<int> capital = {0, 1, 2};
//     cout << s.findMaximizedCapital(k, w, profits, capital) << endl;
//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Create a vector of pairs where each pair is (capital, profit)
        vector<pair<int, int>> projects;
        int n = profits.size();
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;
        int i = 0;

        while (k > 0) {
            // Add all the projects that can be started with the current capital to the max-heap
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }
            
            if (maxHeap.empty()) {
                break;
            }

            // Select the project with the highest profit
            w += maxHeap.top();
            maxHeap.pop();
            k--;
        }

        return w;
    }
};

// #############################################################################################################
// emplace_back     --> better than push_back --> avoids duplicates     --> creates element directly in place in container not like push_back which is like creating a new element and then copying it to the end of container

//  std::vector<std::pair<std::string, int>> students;
//  students.emplace_back("Alice", 20);
//  students.push_back(std::make_pair("Alice", 20));

// ############################################################################################################

int main() {
    Solution s;
    int k = 100000;
    int w = 100000;
    vector<int> profits = {
        10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 
        10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 
        10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 
        10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 
        10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 
        10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 
        10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 
        10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 
        10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 
        10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000
    };
    vector<int> capital = {
        4819, 6598, 5235, 7284, 6819, 2636, 7105, 4823, 9026, 3811, 
        2773, 2437, 5168, 9482, 5941, 9403, 7658, 3926, 4594, 9896, 
        575, 3334, 1461, 6469, 8911, 9220, 9430, 5222, 8566, 5392, 
        3952, 3283, 3116, 9552, 8134, 2440, 638, 7280, 8856, 8103, 
        9106, 6158, 6701, 4563, 6219, 7006, 9885, 3473, 7242, 1394, 
        7037, 4020, 857, 6062, 5707, 575, 193, 4343, 1897, 6512, 
        8224, 9537, 1985, 9355, 8443, 5511, 841, 496, 714, 1789, 
        2214, 4502, 9314, 4390, 3882, 7311, 2078, 3965, 3933, 9812, 
        1052, 2336, 5041, 5678, 3494, 2119, 4198, 5317, 8216, 8376, 
        3204, 3796, 347, 7998, 1102, 1489, 7787, 7868, 3883, 4633
    };

    cout << s.findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}
