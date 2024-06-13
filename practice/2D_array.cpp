#include<iostream>

using namespace std;

bool searchElement(int arr[][10], int n, int m, int key){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==key){
                return true;
            }
        }
    }
    return false;
}

void rowSum(int arr[][10], int n, int m){

    int sum=0;
    int maxi=0;
    int maxIndex=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum+=arr[i][j];
        }
        if(sum>maxi){
            sum=maxi;
            maxIndex=i;
            sum=0;
        }
    }
    cout<<"Max sum is: "<<maxi<<" at row: "<<maxIndex<<endl;
}

void wavePrint(int arr[][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                cout << arr[i][j] << " ";
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl; // Ensure the output ends with a newline for better readability
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    int arr[n][10]; // Adjusting to fit the wavePrint function parameter

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "The entered array is:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Wave print of the array:" << endl;
    wavePrint(arr, n, m);
    return 0;
}
