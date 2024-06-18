#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for(int i=0;i<n;i++){
            sum+=arr[i];
        }

        cout<<"Sum: "<<sum<<endl;

        if(n<3){
            return sum;
        }
        for(int i=3;i<=n;i+=2){
            int windowSum=0;

            for(int j=0;j<i;j++){
                windowSum+=arr[j];
            }

            cout<<"Window Sum: "<<windowSum<<endl;

            sum+=windowSum;

            for(int j=i;j<n;j++){
                windowSum+=arr[j]-arr[j-i];
                sum+=windowSum;
                
                cout<<"Sum: "<<sum<<endl;
            }

        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 4, 2, 5, 3};
    cout << s.sumOddLengthSubarrays(arr) << endl;
    return 0;
}