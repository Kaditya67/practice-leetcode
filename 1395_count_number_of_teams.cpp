#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        for (int j = 0; j < n; ++j) {
            cout<<"j is: "<<j<<endl<<endl;
            // Reset Counters
            cout<<"Reset counters ..."<<endl;
            int leftSmaller = 0, leftGreater = 0;
            int rightSmaller = 0, rightGreater = 0;

            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    leftSmaller++;
                    cout<<"leftSmaller is: "<<leftSmaller<<endl;
                } else if (rating[i] > rating[j]) {
                    leftGreater++;
                    cout<<"leftGreater is: "<<leftGreater<<endl;
                }
            }

            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) {
                    rightSmaller++;
                    cout<<"rightSmaller is: "<<rightSmaller<<endl;
                } else if (rating[k] > rating[j]) {
                    rightGreater++;
                    cout<<"rightGreater is: "<<rightGreater<<endl;
                }
            }

            count += leftSmaller * rightGreater;
            count += leftGreater * rightSmaller;
            cout<<"count is: "<<count<<endl;
            cout<<endl;
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<int> rating1 = {2, 5, 3, 4, 1};
    vector<int> rating2 = {2, 1, 3};
    vector<int> rating3 = {1, 2, 3, 4};

    cout<< "2,5,3,4,1"<<endl;
    cout << "Number of teams for rating1: " << solution.numTeams(rating1) << endl; // Output: 3
    // cout << "Number of teams for rating2: " << solution.numTeams(rating2) << endl; // Output: 0
    // cout << "Number of teams for rating3: " << solution.numTeams(rating3) << endl; // Output: 4

    return 0;
}