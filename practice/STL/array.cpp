#include<iostream>
#include<array>
using namespace std;

int main()
{
    // array<<type,size>
    array<int,5> arr = {1,2,3,4,5};
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<"O(n)"<<endl;
    <<cout<<"Element at 2nd index: "<<arr.at(2)<<endl;

    cout<<"Empty or not: "<<arr.empty()<<endl;

    cout<<"1st element: "<<arr.front()<<endl;
    cout<<"Last element: "<<arr.back()<<endl;


    return 0;
}