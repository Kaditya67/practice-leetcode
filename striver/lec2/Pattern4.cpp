#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the number of rows: ";
    int n;
    cin>>n; 
    cout<<endl;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n+1-i; ++j){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}