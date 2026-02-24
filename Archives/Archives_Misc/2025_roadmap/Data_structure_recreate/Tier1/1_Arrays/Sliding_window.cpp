#include<iostream>
#include <string>
#include <unordered_map>
#include<vector>
#include<strings.h>

using namespace std;

// Fixed Window Size
int slidingWindowSum(vector<int> &arr,int k){   // {1,2,3,4,5} , 3
    // Maximum sum subarray of size k
    int n = arr.size();
    int maxSum=0;
    int windowSum=0;
    int j=0;
    while(j<k){ // 0, 1, 2, 3
        windowSum+=arr[j];
        j++;
    } // 3
    maxSum = windowSum;

    for(int i=k;i<n;i++){
       windowSum += (arr[i] - arr[i-k]);   // 3 , 3-3=0
       maxSum = max(windowSum,maxSum);
    }
    return maxSum;
}

// Variable Window Size
int longestSubstringKDistinct(string s, int k){
    int l =  s.length();
    unordered_map<char, int>mp;
    int maxLen = 0;
    int left = 0 ,right = 0;
    while(right<l){
        mp[s[right]]++;

        if(mp.size()>k){        // erase the element with frequency if mp.size() is greater than k
            mp[s[left]]--;
            if(mp[s[left]]==0){
                mp.erase(s[left]);
            }
            left++;
        }
        maxLen = max(maxLen,right-left+1);
        right++;
    }
    return maxLen;
}
// {
// "e  c  e  b  a"       k = 2
//  lr                   len = 1
//  l  r                 len = 2
//  l     r              len = 2        {e:2,c:1}
//  l        r           {e:2,c:1,b:1}      --> reduce length by erasing left most element from map
//     l     r           {e:1,c:1,b:1}  len = 3, ---> reduce
//        l  r           {c:1,b:1}  len = 2,
//        l     r        len = 3
// }

int main(){
    vector<int>arr = {1,2,3,4,5};
    int k1 = 3;
    int res1 = slidingWindowSum(arr, k1);
    cout<<"Maxisum Subarray sum of size "<<k1<<" is : "<<res1<<endl;

    string s = "eceba";
    int k2 = 2;
    int res2 = longestSubstringKDistinct(s, k2);
    cout<<"Maximum Length of longest Substring with K distanct characters : "<<res2<<endl;
    return 0;
}
