#include<iostream>
#include<math.h>
using namespace std;

int main(){
    // int a=5;
    // int b=6;

    // cout<<(a&b)<<endl;
    // cout<<(a|b)<<endl;
    // cout<<(a^b)<<endl;
    // cout<<(~b)<<endl;

    // cout<<"And Operation"<<endl;
    // for(int i=1;i<20;i++){
    //     cout<<"And of : "<<i<<" and "<<(i+1)<<" is : "<<(i & (i+1))<<endl;
    // }
    // cout<<"Checking left-shift Operation"<<endl;
    // int j=10;
    // for(int i=1;i<20;i++){
    //     cout<<((j<<i) == (j * pow(2, i))) << " Left-shift of : " << j << " is : " << (j << i) << " and power of 2 is : " << (j * pow(2, i)) << endl;
    // }

    int a = 5, b = 5;

    // // Pre-increment
    // cout << "Initial value of a: " << a << endl;
    // cout << "Using pre-increment (++a): " << ++a << endl; // Increment happens before printing
    // cout << "Value of a after pre-increment: " << a << endl;

    // // Post-increment
    // cout << "\nInitial value of b: " << b << endl;
    // cout << "Using post-increment (b++): " << b++ << endl; // Print first, then increment
    // cout << "Value of b after post-increment: " << b << endl;

    cout << "Using post-increment (i++):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // Using pre-increment
    cout << "Using pre-increment (++i):" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}