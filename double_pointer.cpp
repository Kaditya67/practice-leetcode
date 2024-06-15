#include<iostream>

using namespace std;

void updateValue(int **b){
    cout<<b<<endl;
    // b=b+1;
    // cout<<b<<endl;


    cout<<*b<<endl;
    // *b=*b+1;
    // cout<<*b<<endl;

    cout<<**b<<endl;
    **b=**b+1;
    cout<<**b<<endl;

}
int main(){
    int p=5;
    int *a=&p;
    int **b=&a;
    cout<<**b<<endl;

    updateValue(b);

    int arr[5]={1,2,3,4,5};

    int *ptr=&arr[0];
    cout<<ptr<<endl;

    // int *p=arr++;   // not possible because it is changing in symbol table
    // int *p=&arr[0]+1;

    int *q=ptr+1;       // pointer to array can be increased by 1 but not the original one
    cout<<q<<endl;

    cout<<**b<<endl;


    char arr1[]="abcd";     /// This type of character array prints the whole array not the address of it
    char *c=arr1;
    cout<<c<<endl;

    cout<<(c+1)<<endl; // moves from 1st position to next amd prints the value

    return 0;
}