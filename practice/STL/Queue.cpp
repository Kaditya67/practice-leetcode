// FIFO - First In First Out
#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<"Element in the Queue : "<<endl;

    cout << "Element in the Front : " << q.front() << endl;
    q.pop();

    cout << "Element popped." << endl;

    cout << "Element in the Front : " << q.front() << endl;

    return 0;

}
