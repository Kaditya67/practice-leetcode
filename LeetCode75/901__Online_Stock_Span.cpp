// Problem: https://leetcode.com/problems/online-stock-span/
// Difficulty: Hard

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>>st;
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(){
    StockSpanner ss;
    cout << ss.next(100) << endl; // returns 1
    cout << ss.next(80) << endl; // returns 1
    cout << ss.next(60) << endl; // returns 1
    cout << ss.next(70) << endl; // returns 2
    cout << ss.next(60) << endl; // returns 1
    cout << ss.next(75) << endl; // returns 4
    cout << ss.next(85) << endl; // returns 6
    return 0;
}
