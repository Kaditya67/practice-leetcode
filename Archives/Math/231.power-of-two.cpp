// /*
//  * @lc app=leetcode id=231 lang=cpp
//  *
//  * [231] Power of Two
//  */

// // @lc code=start
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n<=0){
//             return false;
//         }
//         return (n&(n-1))==0;
//     }
// };
// // @lc code=end

//
#include<iostream>
using namespace std;

string binaryNum(int num){
    cout<<"Number is : "<<num<<endl;
    string binary; 
    while(num>0){
        cout<<"num is : "<<num<<endl;
        binary = ((num%2==0)? '0':'1')+binary;
        num/=2;
    }
    cout<<endl;
    return binary;
}

int main(){
    //creating binary
    int num1,num2;
    cout<<"Enter Num1 : ";
    cin>>num1;
    // cout<<"Enter Num2 : ";
    // cin>>num2;

    string binary_num1=binaryNum(num1);
    string binary_num2=binaryNum(num1+1);
    cout<<binary_num1<<endl;
    cout<<binary_num2<<endl;
    return 0;
}