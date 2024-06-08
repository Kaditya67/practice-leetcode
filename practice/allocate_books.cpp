#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int arr[],int n,int m,int mid){
    
    int student=1;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        if(sum+arr[i]<=mid){        // sum is greater than mid
            sum+=arr[i];
        }else{
            student++;
            if(student>m || arr[i]>mid){        // condition is satisfied
                return false;
            }
            // Start new for a new student
            // sum=0
            // give the current value to that new student
            sum=arr[i];
            
        }
    }
    
    return true;    
}

int allocateBooks(int arr[], int n, int m) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int min = 0;
    int max = sum;
    int ans = -1;

    while (min <= max) {
        int mid = min + (max - min) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }
    
    return ans;
}

int main() {
    int n, m;
    cout << "Enter the number of books: ";
    cin >> n;

    int arr[n];
    cout << "Enter the number of pages in each book: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number of students: ";
    cin >> m;

    int result = allocateBooks(arr, n, m);
    if (result == -1) {
        cout << "It is not possible to allocate books." << endl;
    } else {
        cout << "The minimum number of pages that can be allocated to a student is: " << result << endl;
    }

    return 0;
}
