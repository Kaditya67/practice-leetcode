#include<iostream>

using namespace std;

int fastest_exponentation(int a,int b){

    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b%2==0)
        return fastest_exponentation(a,b/2)*fastest_exponentation(a,b/2);
    else
        return a*fastest_exponentation(a,b/2)*fastest_exponentation(a,b/2);
}

int main(){

    int a,b;

    cin>>a>>b;

    cout<<fastest_exponentation(a,b);

    return 0;
}