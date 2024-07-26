#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double avgTime=0;
        int currTime=customers[0][0];

        for(int i=0;i<n;i++){
            if(currTime<customers[i][0]){

                cout<<endl;
                currTime=customers[i][0];
                cout<<"Bigger Time"<<endl;
            }
            currTime+=customers[i][1];  // Add the time takes to cook
            cout<<"Current time: "<<currTime<<endl;
            avgTime+=currTime-customers[i][0];  // current time - arrival time
            cout<<"Average time: "<<avgTime<<endl;
        }

        return avgTime/n;
    }
};

int main() {
    // [5,2],[5,4],[10,3],[20,1]
    vector<vector<int>> customers = {{5, 2}, {5, 4}, {10, 3}, {20, 1}};
    Solution s;
    cout << s.averageWaitingTime(customers) << endl;

    return 0;
}