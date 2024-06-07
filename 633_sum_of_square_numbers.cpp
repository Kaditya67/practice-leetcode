#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) // 29
    {
    	if(c<0)
    		return false;
    	long int left=0,right=sqrt(c);  
    	while(left<=right)
    	{
    		long int cur=left*left+right*right;
    		if(cur<c)                       // 25 < 29      --->  26 < 29 -- > 29==29(false)
    			left++;     // 1, 2
    		else if(cur>c)
    			right--;    // 5
    		else 
    			return true;                // returning True for 29==29
    	}    
    	return false;
    }
};

int main() {
    Solution sol;
    int number;
    cout << "Enter a number: ";
    cin >> number;

    bool result = sol.judgeSquareSum(number);
    if (result) {
        cout << number << " can be expressed as the sum of two squares." << endl;
    } else {
        cout << number << " cannot be expressed as the sum of two squares." << endl;
    }

    return 0;
}


// 30


// sqrt(30) = 5.5  --> 5

// 25<30            ---> +0
// 26<30            ---> +1
// 29<30            ---> +4
// 34>30            ---> +9     ---> right--   ---> 5-1 = 4
// 16+9=25<30       ---> +9    ---> left++    ---> 3+1 = 4  
// condition : left<=right  ---> false
// return false 