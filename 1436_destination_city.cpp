#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        string curr = paths[0][1];

        bool found;
        do {
            found = false;
            for (int i = 0; i < n; ++i) {
                if (paths[i][0] == curr) {
                    curr = paths[i][1];
                    found = true;
                    break;  // Exit the loop early as we updated curr
                }
            }
        } while (found);

        return curr;
    }
};

int main() {
    // Example usage
    vector<vector<string>> paths = {
        {"London", "New York"},
        {"New York", "Lima"},
        {"Lima", "Sao Paulo"}
    };

    Solution sol;
    string result = sol.destCity(paths);

    // Print result
    cout << "Destination City: " << result << endl;

    return 0;
}
