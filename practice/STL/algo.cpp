#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout<<"Finding 5:"<<binary_search(arr.begin(), arr.end(), 5)<<endl;

    // Returns Iterator
    cout<<"Lower Bound of 5: "<<lower_bound(arr.begin(), arr.end(), 5) - arr.begin();
    cout<<"Upper Bound of 5: "<<upper_bound(arr.begin(), arr.end(), 5) - arr.begin();

    int a=5;
    int b=10;
    cout<<"Max: "<<max(a,b);
    cout<<"Min: "<<min(a,b);
    
    cout<<"Before swap: a: "<<a<<" b: "<<b<<endl;
    // swap(a,b);
    swap(a,b);
    cout<<"a: "<<a<<" b: "<<b<<endl;

    string s1="abcd";
    reverse(s1.begin(), s1.end());
    cout<<s1<<endl;  

    cout<<"Rotate by one : ";
    rotate(arr.begin(), arr.begin() + 1, arr.end());
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}