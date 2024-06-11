#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> d;
    d.push_back(1);     // 1
    d.push_front(0);    // 0 1
    d.push_front(2);    // 2 0 1
    d.push_back(3);     // 2 0 1 3
    for(int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    d.pop_back();
    for(int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    d.pop_front();
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Size of deque: "<<d.size()<<endl;

    cout<<"Empty or not: "<<d.empty()<<endl;

    // index, value

    for(int i=0;i<d.size();i++){
        cout<<i<<"->"<<d[i]<<" ";
    }

    cout<<endl;
    // index is auto adjusted 
    // 
    // cout<<"Element at 2nd index: "<<d.at(2)<<endl;

    // cout<<"Element at 2nd index: "<<d[2]<<endl;

    cout<<"Front element: "<<d.front()<<endl;

    cout<<"Last element: "<<d.back()<<endl;

    // erase
    cout<<"Before erase: ";
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"After erase: ";
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}