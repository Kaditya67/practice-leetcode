#include<iostream>
using namespace std;

// class Solution {
// public:
//     int passThePillow(int n, int time) {
//         // time/n-1            ---> 1       --> count in reverse
//         // 2 --> count normal

//         if(time>=n){
//             int check=time/(n-1);
//             cout<<"check: "<<check<<endl;

//             if((check%2)==0){
//                 cout<<"Even: "<<(check%2)<<endl;
//                 return (time%(n-1))+1;
//             }else{
//                 cout<<"Odd : "<<(time%(n-1))<<endl;
//                 return n-(time%(n-1));
//             }
//         }else{
//             return time+1;
//         }
//     }
// };

class Solution {
public:
    int passThePillow(int n, int time) {
        
        if(time>=n){
            int check=time/(n-1);
            if((check%2)==0){
                return (time%(n-1))+1;
            }
            return n-(time%(n-1));
        }
        return time+1;
    }
};

int main(){
    int n,time;
    cin>>n>>time;
    Solution obj;
    cout<<obj.passThePillow(n,time);
    return 0;
}