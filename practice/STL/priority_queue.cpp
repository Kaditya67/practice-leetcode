#include<iostream>
#include<queue>

using namespace std;

int main(){
    
    // Max heap -- > Max element will be at top
    priority_queue<int> pq;
    pq.push(1);
    pq.push(4);
    pq.push(3);
    pq.push(2);

    // Display

    int a = pq.size();
    cout<<"Size: "<<a<<endl;
    for(int i=0;i<a;i++){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    // min heap
    priority_queue<int, vector<int>, greater<int>> qp;

    qp.push(5);
    qp.push(4);
    qp.push(3);
    qp.push(2); 
    qp.push(1);

    int b = qp.size();
    cout<<"\nSize: "<<b<<endl;
    for(int i=0;i<b;i++){
        cout<<qp.top()<<" ";
        qp.pop();
    }
    return 0;
}