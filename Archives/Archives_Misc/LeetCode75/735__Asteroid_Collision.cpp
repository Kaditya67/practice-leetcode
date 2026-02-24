// Problem: https://leetcode.com/problems/asteroid-collision/
// Difficulty: Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int ast : asteroids){
            if(ast > 0){
                st.push(ast);
            } else {
                while(!st.empty() && st.top() > 0){
                    if(st.top() < -ast){
                        st.pop();  // smaller positive asteroid destroyed
                    } else if(st.top() == -ast){
                        st.pop();  // both destroy each other
                        ast = 0;
                        break;
                    } else {
                        ast = 0;  // negative asteroid destroyed
                        break;
                    }
                }
                if(ast != 0){
                    st.push(ast);  // negative asteroid survives
                }
            }
        }

        vector<int> res(st.size());
        for(int i = st.size() - 1; i >= 0; --i){
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> asteroids = {5,10,-5};
    vector<int> res = s.asteroidCollision(asteroids);
    for(int i:res) cout << i << " ";
    cout << endl;
    return 0;
}
