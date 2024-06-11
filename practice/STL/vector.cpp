// Dynamic array
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;
    v.push_back(1); // 1
    v.push_back(2); // 2
    v.push_back(3); // 4

    cout<<"Size(No of elements) : "<<v.size()<<endl;
    cout<<"Capacity(Space available) : "<<v.capacity()<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;


    cout<<"Element at 2nd index: "<<v.at(2)<<endl;

    cout<<"Empty or not: "<<v.empty()<<endl;

    cout<<"1st element: "<<v.front()<<endl;
    cout<<"Last element: "<<v.back()<<endl;

    cout<<endl<<endl;
    cout<<"Before pop: Size "<<v.size()<<endl;
    v.pop_back();
    cout<<"After pop:  Size"<<v.size()<<endl;

    cout<<endl<<endl;
    cout<<"Before clear: Size : "<<v.size()<<endl;
    v.clear(); // reduces size to 0
    // capacity remains same
    cout<<"After clear: Size : "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;

    
    // vector<size,initialize> v_name;
    vector<5,10> v1;

    // copy one vector to another
    vector<int> v2(v1);

    return 0;
}