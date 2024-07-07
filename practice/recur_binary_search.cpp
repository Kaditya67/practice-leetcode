#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(const vector<int>& vec, int key, int start, int end) {
    if (start > end) {
        return false;
    }

    int mid = start + (end - start) / 2;
    if (vec[mid] == key) {
        return true;
    } else if (vec[mid] > key) {
        return binarySearch(vec, key, start, mid - 1);
    } else {
        return binarySearch(vec, key, mid + 1, end);
    }
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    int key = 5;
    
    bool ans = binarySearch(vec, key, 0, vec.size() - 1);

    if (ans) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
