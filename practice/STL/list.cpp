#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    cout<<"Size: "<<l.size()<<endl;
    
    // l.clear();
    // cout<<"Size: "<<l.size()<<endl;

    for(int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    // pop_back
    l.pop_back();

    for(int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Size: "<<l.size()<<endl;

    cout<<endl;

    // erase

    // l.erase(l.begin());  // erases the only element i.e 1st element

    l.erase(l.begin(), l.end());
    cout<<"After Erase : "<<endl;
    for(int i:l){
        cout<<i<<" ";
    }

    cout<<"New List"<<endl;
    list<int> l2(5, 100);   // 5 elements with value 100
    // cout<<endl;
    for(int i:l2)
    {
        cout<<i<<" ";
    }
    return 0;
}