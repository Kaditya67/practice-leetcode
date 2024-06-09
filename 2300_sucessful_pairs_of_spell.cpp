#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result(spells.size(), 0);       // fixed size--> More efficient
        sort(potions.begin(), potions.end());
        
        for (int i = 0; i < spells.size(); ++i) {
            int low = 0;
            int high = potions.size() - 1;
            int mid;
            while (low <= high) {
                mid = low + (high - low) / 2;
                cout<<"Mid : "<<mid<<endl;
                
                if ((long long)spells[i] * (long long)potions[mid] >= success){      // spells*potions = success?
                    high = mid - 1;
                    cout<<"High : "<<high<<endl;
                }
                else{
                    low = mid + 1;
                    cout<<"Low : "<<low<<endl;
                }
            }
            
            cout<<"result[i] = potions.size() - low : "<<potions.size()<<" - "<<low<<" = ";
            result[i] = potions.size() - low;
            cout<<result[i];
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    vector<int> result = solution.successfulPairs(spells, potions, success);

    for (int count : result) {
        cout << count << " ";
    }

    return 0;
}


// Dry Run

// 5,1,3
// 1,2,3,4,5
// 7

// 5*1=5
// 5*2=10
// 5*3=15       --> mid=2
// 5*4=20
// 5*5=25

// high = mid - 1 ---> high = 2 - 1 = 1
// mid=0+(1-0)/2=0

// 5*1=5        --> mid=0
// 5*2=10
// 5*3=15       
// 5*4=20
// 5*5=25


// else block
// low=mid+1=1
// low==high        --> True
// mid = 1+(1-1)/2=1


// 5*1=5       
// 5*2=10    --> mid=1
// 5*3=15       
// 5*4=20
// 5*5=25

// high=0
// while condition ---> false

// result = total_size_of_potion - low = 5-1=4

// result=0
// result=3

// return result
