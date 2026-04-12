#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the number of rows: ";
    int n;
    cin>>n;
    cout<<endl;

    for(int i=0;i<n;++i){
        for(int j=0; j<n-i; ++j){
            cout<<" ";
        }
        for(int j=0;j<i+1;++j){
            cout<<"*";
        }
        for(int j=0;j<i;++j){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}