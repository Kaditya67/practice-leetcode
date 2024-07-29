#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//? ################################ Vector of Integers ###########################
// bool mycomparator(int a, int b) {
//     // return a < b; 
//     if(a<b){    // ascending
//         return true ;
//     }
//     return false;
// }

// int main() {
//     vector<int> vec={2,4,3,1,5,7,0};

//     sort(vec.begin(), vec.end(), mycomparator);

//     cout << "Sorted vector: ";
//     for (int num : vec) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }

bool mycomparator(int a, int b) {
    // return a < b; 
    if(a<b){    // ascending
        return true ;
    }
    return false;
}

int main() {
    vector<int> vec={2,4,3,1,5,7,0};

    sort(vec.begin(), vec.end(), mycomparator);

    cout << "Sorted vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
