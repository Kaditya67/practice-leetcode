#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;

        for (int i = 0; i < hand.size(); i++) {
            mp[hand[i]]++;
        }

        for (auto x = mp.begin(); x != mp.end();) {
            if (x->second > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (mp[x->first + i] > 0)
                        mp[x->first + i]--;
                    else
                        return false;
                }
            } else {
                x++;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;
    bool result = solution.isNStraightHand(hand, groupSize);
    cout << (result ? "True" : "False") << endl;

    return 0;
}
