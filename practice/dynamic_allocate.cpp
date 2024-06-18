#include<iostream>
using namespace std;


// stack is short and heap is large

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    // int *arr = new int[n];  // Creating 1D array
    int** arr= new int*[n];  // Creating 2D array   
    for(int i=0;i<n;i++){
        arr[i] = new int[m];        // creating 1D array ---> row
        for(int j=0;j<m;j++){               // take this m as column
            cin>>arr[i][j];     // j --> column
        }
    }

    cout<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // releasing memory

    for(int i=0;i<n;i++){
        delete [] arr[i];   
    }
    delete [] arr;
    return 0;
}