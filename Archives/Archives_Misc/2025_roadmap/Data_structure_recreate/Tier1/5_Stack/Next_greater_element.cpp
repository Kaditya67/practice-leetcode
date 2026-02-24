#include<bits/stdc++.h>
using namespace std;

// Monotonic Stack - The stack is used to find the immediate next greater element to the right
// This will be creating a decreasing stack
vector<int> nextGreaterElements(const vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    vector<int> res(n,-1);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){ // Remove all smaller or equalto elements
            st.pop();
        }

        // This will be greatest element seen uptil now
        if(!st.empty()){
            res[i] = st.top();
        }

        st.push(arr[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {4, 5, 2, 25, 7, 8};
    vector<int> nge = nextGreaterElements(arr);

    cout << "Next Greater Elements:\n";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " --> " << nge[i] << endl;
    }

    return 0;
}
