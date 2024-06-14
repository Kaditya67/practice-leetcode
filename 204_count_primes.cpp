#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// // class Solution {
// // private:
// //     bool isPrime(int n){
// //         for(int i=2;i<n;i++){
// //             if(n%i==0){
// //                 return false;
// //             }
// //         }
// //         return true;
// //     }
// // public:
// //     int countPrimes(int n) {
// //         int count=0;

// //         for(int i=2;i<n;i++){
// //             if(isPrime(i)){
// //                 count++;
// //             }
// //         }
// //         return count;
// //     }
// // };


// class Solution {
// public:
//     int countPrimes(int n) {
//         int count=0;
//         vector<bool> v(n,1);

//         for(int i=2;i<n;i++){
           
//             if(v[i]==1){
//                 count++;
//                 for(int j=2*i;j<n;j+=i){
//                     v[j]=0;
//                 }
//             }
//         }
//         return count;
//     }
// };


// Sieve of Eratosthenes

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; // There are no primes less than 2

        vector<char> v(n, 1); // Use char instead of bool
        v[0] = v[1] = 0; // 0 and 1 are not primes

        for (int i = 2; i * i < n; i++) {
            if (v[i] == 1) {
                for (int j = i * i; j < n; j += i) {
                    v[j] = 0;
                }
            }
        }
        return count(v.begin(), v.end(), 1);
    }
};

int main(){

    Solution s;

    cout<<s.countPrimes(10);

    return 0;
}

// Data Type: Using std::vector<char> instead of std::vector<bool> can sometimes be more efficient because vector<bool>
