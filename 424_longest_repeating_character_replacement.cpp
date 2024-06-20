#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0); 
        int max_count = 0; 
        int start = 0; 
        int max_length = 0;
        
        for (int end = 0; end < s.size(); end++) {
            cnt[s[end] - 'A']++; 
            max_count = max(max_count, cnt[s[end] - 'A']);
            
            if (end - start + 1 - max_count > k) {      // If the difference is greater then shrink the window
                cnt[s[start] - 'A']--; // decrase the count of leaving character
                start++; 
            }
            
            max_length = max(max_length, end - start + 1);
        }
        
        return max_length;
    }
};

int main(){

}
