/**
 * PROBLEM: LeetCode 703 - Kth Largest Element in a Stream
 * ORDER: 08
 * ATOMIC TOPIC: Priority Queue Dynamic
 * 
 * DESCRIPTION:
 * Design a class to find the kth largest element in a stream. Note that it is the nth 
 * largest element in the sorted order, not the kth distinct element.
 * 
 * CONSTRAINTS:
 * - 1 <= k <= 10^4
 * - 0 <= nums.length <= 10^4
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        // TODO: Initialize min-heap to size k
    }
    
    int add(int val) {
        // TODO: Maintain min-heap size k
        return 0;
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    cout << "Add 3: " << kthLargest.add(3) << " (Expected: 4)" << endl;
    cout << "Add 5: " << kthLargest.add(5) << " (Expected: 5)" << endl;
    cout << "Add 10: " << kthLargest.add(10) << " (Expected: 5)" << endl;

    return 0;
}
