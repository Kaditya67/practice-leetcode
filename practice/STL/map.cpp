// map -->  key value pair
// map is an associative container
// key is unique
// map is sorted

#include <iostream>
#include <map>
using namespace std;

int main(){

    map<int, string> m;

    m[1] = 'a';
    m[5] = 'b';
    m[2] = 'c';
    m[10] = 'd';


    
    cout<<"Sorted map(Before Erase): "<<endl;
    for(auto i:m){
        cout<<i.first<<endl;
    }


    // finding an element ---> count()

    cout<<"Element found or not: "<<m.count(2)<<endl;


    // Erase
    m.erase(2);

    cout<<"Sorted map(After Erase): "<<endl;
    for(auto i:m){
        cout<<i.first<<endl;
    }


    auto it=m.find(5);
    cout<<"Element found: "<<(*it).first<<endl;
    for(auto i=it;i!=m.end();i++){
        cout<<(*i).first<<endl;
    }
    return 0;
}