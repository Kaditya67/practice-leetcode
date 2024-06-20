#include <vector>
#include <algorithm>
using namespace std;

class Solution {

private:
    bool canMove(vector<int>& position, int force, int m) {
        int n = position.size();
        int count = 1;
        int prev = position[0];
        for(int i = 1; i < n; i++) {
            if(position[i] - prev >= force) {
                count++;
                prev = position[i];
            }
            if (count >= m) {
                return true;
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        
        int minForce = 1;
        int maxForce = position[n-1] - position[0];
        int res = -1;

        while(minForce <= maxForce) {
            int mid = minForce + (maxForce - minForce) / 2;
            if(canMove(position, mid, m)) {
                res = mid;
                minForce = mid + 1;
            } else {
                maxForce = mid - 1;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> position = {1,2,3,4,7};
    int m = 3;
    cout << s.maxDistance(position, m) << endl;

    return 0;
}