#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCount=0;
        for(int i=0;i<arr.size()&& oddCount<3;i++){
            oddCount = arr[i] % 2 ? oddCount+1 : 0;
        }
        return oddCount==3;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,34,3,4,5,7,23,12};
    cout << s.threeConsecutiveOdds(arr) << endl;
    return 0;
}