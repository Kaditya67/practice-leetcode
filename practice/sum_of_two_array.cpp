#include<iostream>
#include <vector>
#include <algorithm> // For reverse
using namespace std;

vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {
    if (n == 0 && m == 0) return {}; // Both arrays are empty

    int indexA = n - 1;
    int indexB = m - 1;
    vector<int> ans;
    int carry = 0;

    while (indexA >= 0 && indexB >= 0) {
        int val1 = a[indexA];
        int val2 = b[indexB];

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);

        indexA--;
        indexB--;
    }

    while (indexA >= 0) {
        int sum = a[indexA] + carry;
        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);
        indexA--;
    }

    while (indexB >= 0) {
        int sum = b[indexB] + carry;
        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);
        indexB--;
    }

    // Handle the remaining carry, if any
    if (carry > 0) {
        ans.push_back(carry);
    }

    reverse(ans.begin(), ans.end()); // Reverse the result to get the correct order
    return ans;
}

int main() {
    vector<int> a = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    vector<int> b = {9, 9, 9, 9};
    vector<int> ans = findArraySum(a, a.size(), b, b.size());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}