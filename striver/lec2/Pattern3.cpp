#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the number of rows: ";
    int n;
    cin>>n; 
    cout<<endl;

    for(int i=1;i<=n;++i){
        for(int j=0; j<i; ++j){
            cout<<i<<" ";
        }
        cout<<endl;

    }
    return 0;
}