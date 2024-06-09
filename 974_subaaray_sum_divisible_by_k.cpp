// [4,5,0,-2,-3,1], k = 5

// [0],         ---> sum = 0
// [5],         ---> sum = 5
// [5, 0],       ---> sum = 5
// [-2, -3],          ---> sum = -5
// [0, -2, -3],          ---> sum = -5
// [5, 0, -2, -3],           ---> sum = 0
// [4, 5, 0, -2, -3, 1],         ---> sum = 5

// 0%5=0               0:2
// 4%5=4               2:1
// 9%5=4               4:4
// 9%5=4   
// 7%5=2
// 4%5=4
// 5%5=0

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ############################# Brute Force ###########################################               O(n^3)

// int subarraySum(vector<int>& nums, int k) {

//     int sum = 0;
//     int count = 0;
//     for (int i = 0; i < nums.size(); i++){
//         for(int j = i; j < nums.size(); j++){
//             sum = 0;
//             for(int k = i; k <= j; k++){
//                 sum += nums[k];
//             }
//             if(sum % k == 0){
//                 count++;
//             }
//         }

//     }
//     return count;
// }

// ################################# Better Approach ####################################### o(n^2)

// int subarraysDivByK(vector<int>& nums, int k) {
//     int n=nums.size();
//     int count=0;
//     int sum=0;


//     // Make cumulative sum of vector

//     for(int i=0;i<n;i++){
//         sum+=nums[i];
//         nums[i]=sum;
//         cout<<"i is : "<<i<<" and nums[i] is :"<<nums[i]<<endl;
//     }
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             sum= (i==0)?nums[j]:nums[j]-nums[i-1];
//             if(sum%k==0){       // if sum is divided by k then  increase count
//                 count++;
//             }
//         }
//     }
//     return count;
// }



// Dry Run

// 4,5,0,-2,-3,1
// cumulative sum : 4, 9, 9, 7, 4, 5

// sum from i=1 to j=5

// 5+0+(-2)+(-3)+1=1

// from CS,
// nums[j]-nums[i-1]
// 5-4=1

// ############################## Optimal Approach ##########################################

    // remainder  (k=5)     (s1=6) (s2=11)      (s2-s1=5)   
        // if s1%k==1                   (s1=k*n+k)---> remainder k
        // if s2%k==1
        // then (s2-s1)%k==0        // It is didvisible by k since both the ends have same remainder
        // Handle negative remainders for negative k
        
// Map
// remainder | count
// 0         | 1

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    int sum = 0;
    int count = 0;
    prefixSumCount[0] = 1;
    cout<<"sum is : "<<sum<<"  prefix sum count is : "<<prefixSumCount[0]<<endl;
    for (int num : nums) {
        sum += num;
        cout<<"Sum is : "<<sum;
        int remainder = (sum % k + k) % k;          // sum%k is the same as (sum%k + k)%k   --> This will not store the negative remainder
        cout<<"   Remainder is : "<<remainder;
        if (prefixSumCount.find(remainder) != prefixSumCount.end()) {       // If  sum is already seen
            count += prefixSumCount[remainder];
            cout<<"   Count is : "<<count;
        }
        prefixSumCount[remainder]++;
        cout<<"   Prefix sum count is : "<<prefixSumCount[remainder];
        cout<<"\n"<<endl;
    }
    return count;
}

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << "Number of subarrays: " << subarraysDivByK(nums, k) << endl;
    return 0;
}
