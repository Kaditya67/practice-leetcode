#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int asteroid : asteroids) {
            bool collision = false;
            while(!st.empty() && asteroid < 0 && st.top() > 0) {
                if(abs(st.top()) < abs(asteroid)) {
                    st.pop();
                    continue;
                } else if(abs(st.top()) == abs(asteroid)) {
                    st.pop();
                }
                collision = true;
                break;
            }
            if(!collision) {
                st.push(asteroid);
            }
        }
        
        vector<int> result(st.size());
        for(int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};


int main(){
    Solution s;
    vector<int> asteroids = {-2, -1, 1, 2};
    vector<int> result = s.asteroidCollision(asteroids);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}