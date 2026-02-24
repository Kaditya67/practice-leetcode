#include<bits/stdc++.h>
using namespace std;

int bruteGcd(int a, int b){
    int res = 1;                    //* Everything is divisible by 1 by default
    for(int i=1; i<=min(a,b);i++){
        if(a%i==0 and b%i==0){      // ? IF both divides
            res = i;
        }
    }
    return res;
}

// ✅ Efficient: Euclidean Algorithm
//? While Loop
int gcd_loop(int a,int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

//? Recursive : Most Used
int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);       // Swap the arguments and while swapping try to divide any one
}


// For example --> Divide a by b
// gcd(48, 18) → b ≠ 0 ⇒ return gcd(18, 48 % 18) = gcd(18, 12)
// gcd(18, 12) → b ≠ 0 ⇒ return gcd(12, 18 % 12) = gcd(12, 6)
// gcd(12, 6)  → b ≠ 0 ⇒ return gcd(6, 12 % 6)  = gcd(6, 0)
// gcd(6, 0)   → b == 0 ⇒ return a = 6

// For reverse
// gcd(18, 48)
//  └──> gcd(48, 18)    // Swaps normally because 18 is smaller than 48, so no effect of modulus
//        └──> gcd(18, 12)
//              └──> gcd(12, 6)
//                    └──> gcd(6, 0) → return 6
//                    ← return 6
//              ← return 6
//        ← return 6
//  ← return 6

int main(){
    int a,b;
    cout<<"Enter two Numbers(space separated) : ";
    cin>>a>>b;
    int result = bruteGcd(a,b);
    cout<<"Result is : "<<result<<endl;
    return 0;
}