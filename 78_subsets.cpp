#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function to print the current state of subsets
    void printArray(const vector<vector<int>> &res)
    {
        cout << "Current subsets: [";
        for (const auto &subset : res)
        {
            cout << "{ ";
            for (int num : subset)
            {
                cout << num << " ";
            }
            cout << "} ";
        }
        cout << "]" << endl;
    }

    // Function to visualize the current subset being constructed
    void visualizeBacktrack(int start, const vector<int> &curr, const string &action)
    {
        cout << "At index " << start << ", action: " << action << ", current subset: { ";
        for (int num : curr)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    // The backtrack function generates subsets by including or excluding elements
    void backtrack(vector<int> &nums, int start, vector<int> &curr, vector<vector<int>> &res)
    {
        // Base case: If we have processed all elements, add the current subset to the result
        if (start >= nums.size())
        {
            res.push_back(curr);
            visualizeBacktrack(start, curr, "Add to result");
            printArray(res);
            return;
        }

        // Exclude the current element and proceed
        visualizeBacktrack(start, curr, "Exclude");
        backtrack(nums, start + 1, curr, res);

        // Include the current element and proceed
        curr.push_back(nums[start]);
        visualizeBacktrack(start, curr, "Include");
        backtrack(nums, start + 1, curr, res);

        // Backtrack: Remove the last element to explore other possibilities
        curr.pop_back();
        visualizeBacktrack(start, curr, "Backtrack");
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;       // To store all subsets
        vector<int> curr;              // To store the current subset
        backtrack(nums, 0, curr, res); // Start backtracking from index 0
        return res;
    }
};

int main()
{
    vector<int> nums = {0,1}; // Example input
    Solution s;
    vector<vector<int>> res = s.subsets(nums); // Get all subsets

    // Print all subsets
    cout << "\nFinal subsets:" << endl;
    s.printArray(res);

    return 0;
}
