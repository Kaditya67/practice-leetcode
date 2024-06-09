#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& piles, int mid, int h) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            // Calculate the required hours
            hours += piles[i] / mid;
            cout<<"Required hours: "<<hours<<endl;

            // Check if there is a remainder
            cout<<"Remainder: "<<(piles[i] % mid)<<endl;
            if (piles[i] % mid != 0) {
                cout<<"One more hour needed"<<endl;
                hours++;
            }
            cout<<endl;
        }

        cout<<"TotalRequired hours: "<<hours<<endl;
        cout<<"Statisfies or not : "<<(hours<=h)<<endl;
        cout<<"______________________________________"<<endl;
        cout<<endl;
        return hours <= h;  // Return true if required hours is less than or equal to given hours
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        // int maxi = 0;
        // for (int num : piles) {
        //     maxi = max(maxi, num);
        // }
        // int high = maxi;
        
        int high=*max_element(piles.begin(), piles.end());      // Prevents time exceeding limit
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            cout<<"Mid: "<<mid<<endl;
            if (check(piles, mid, h)) {
                high = mid;
                cout<<"High: "<<high<<endl;
            } else {
                low = mid + 1;
                cout<<"Low: "<<low<<endl;
            }
        }
        cout<<"Out of loop as :- "<<"High : "<<high<<" Low : "<<low<<endl;
        return low;
    }
};

int main() {
    Solution solution;
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Minimum eating speed for piles1: " << solution.minEatingSpeed(piles1, h1) << endl;

    // vector<int> piles2 = {30, 11, 23, 4, 20};
    // int h2 = 5;
    // cout << "Minimum eating speed for piles2: " << solution.minEatingSpeed(piles2, h2) << endl;

    // vector<int> piles3 = {30, 11, 23, 4, 20};
    // int h3 = 6;
    // cout << "Minimum eating speed for piles3: " << solution.minEatingSpeed(piles3, h3) << endl;

    return 0;
}
