#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    void print(int* arr, int size){
        for(int i = 0; i < size; ++i) {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }

    int minimumPushes(string& word) {
        int freq[26] = {0};
        for(char c: word) 
            freq[c - 'a']++;
        
        // Print frequency array before sorting
        print(freq, 26);

        sort(freq, freq + 26, greater<int>());
        
        // Print frequency array after sorting
        print(freq, 26);

        int sz = 0, push = 1, ans = 0;
        for(; sz < 26 && freq[sz] != 0; sz++) {
            if (sz >= 8 && sz % 8 == 0) push++;
            ans += freq[sz] * push;    
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main() {
    Solution sol;
    string word = "exampleword";
    cout << "Minimum pushes: " << sol.minimumPushes(word) << endl;
    return 0;
}
