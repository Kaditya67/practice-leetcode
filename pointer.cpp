#include<iostream>
#include<vector>
using namespace std;

int main(){

    // int a = 10;
    // int *p = &a;
    // cout<<"Value of p: *p "<<*p<<endl;
    // cout<<"Address of p: p "<<p<<endl;

    // int arr[10]={1,2,3,4,5,6,7,8,9,10};

    // int *q = arr;
    // int *m=&arr[0];
    // cout<<"Value of q: *q "<<*q<<endl;
    // cout<<"Address of q: q "<<q<<endl;

    // cout<<"Value of m: *m "<<*m<<endl;
    // cout<<"Address of m: m "<<m<<endl;


    // cout<<"Size of arr: "<<sizeof(arr)<<endl;
    // cout<<"Size of p: "<<sizeof(p)<<endl;       // 8 bytes

    // cout<<"Size of a: "<<sizeof(a)<<endl;
    // cout<<"Size of *p: "<<sizeof(*p)<<endl;

    // cout<<"Size of q: "<<sizeof(q)<<endl;   // 8 bytes
    // cout<<"Size of m: "<<sizeof(m)<<endl;   // 8 bytes


    // cout<<"Size of arr: "<<sizeof(&arr)<<endl;
    // cout<<"Size of p: "<<sizeof(&p)<<endl;       // 8 bytes


    char a[10] = "a";  // Initialize the array with a string literal

    char *b = &a[0];  // Pointer to the first element of the array
    cout << "Value of b: " << *b << endl;  // Dereference pointer to get the value at that address
    cout << "Address of b: " << &b << endl;  // Print the address in a proper format




    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    vector<int> *ptr = &arr; // Corrected line

    // cout << "Value of ptr: " << (*ptr)[0] << endl; // Dereferencing pointer to access elements
    cout << "Address of ptr: " << ptr << endl;

    cout << "Size of arr: " << sizeof(arr) << endl;
    cout << "Size of ptr: " << sizeof(ptr) << endl;
    return 0;

}