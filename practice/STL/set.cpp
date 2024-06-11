// unique set
#include <iostream>
#include <set>
using namespace std;

int main(){
    // set is slow
    // unordered_set is faster-->random values
    set<int> s;
    s.insert(1);
    s.insert(10);
    s.insert(3);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(9);
    s.insert(9);

    for(auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;

    //count O(n)
    if(s.count(9) > 0){     // 1 or 0 ----> for found or not
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

    //find  O(logn)
    set<int>::iterator it;      // set iterator
    it = s.find(9);     // return iterator to 9
    cout<<"it: "<<*it<<endl;
    if(it != s.end()){
        cout<<"Element found: "<<*it<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }


    // Start after the iterator
    for(auto i=it;i!=s.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;



    s.erase(9);
    // s.erase(s.begin()+2);
    return 0;
}