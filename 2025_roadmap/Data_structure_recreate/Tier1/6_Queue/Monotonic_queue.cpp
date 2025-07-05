#include <bits/stdc++.h>
using namespace std;

class MonotonicQueue {
private:
    deque<int> dq;

public:
    void push(int val) {
        while (!dq.empty() && dq.back() < val) {
            dq.pop_back();  // Maintain decreasing order
        }
        dq.push_back(val);
    }

    void pop(int val) {
        if (!dq.empty() && dq.front() == val) {
            dq.pop_front();  // Remove element going out of window
        }
    }

    int getMax() {
        return dq.empty() ? -1 : dq.front();
    }
};

vector<int> slidingWindowMax(vector<int>& nums, int k) {
    vector<int> result;
    MonotonicQueue mq;

    for (int i = 0; i < nums.size(); ++i) {
        mq.push(nums[i]);

        if (i >= k - 1) {
            result.push_back(mq.getMax());
            mq.pop(nums[i - k + 1]); // Remove the element that’s sliding out
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = slidingWindowMax(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int val : res) cout << val << " ";
    cout << endl;

    return 0;
}