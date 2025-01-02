#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {0,2,1,-6,6,-7,9,1,2,0,1};
    int sum = 0;
     
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
 
    if(sum % 3 == 0){
        int target = sum / 3;
        int currSum = 0;
        int count = 0;
         
        for(int i=0; i<arr.size(); i++){
            currSum += arr[i];
            if(currSum == target){
                count++;
                currSum = 0;
            }
            // If we have found 2 partitions, we can output true
            if(count == 3){
                cout << "true";
                return 0; 
            }
        }
        cout << "false";
    }else{
        cout << "false";  
    }
    
    return 0;
}
