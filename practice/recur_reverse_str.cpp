#include <iostream>
#include <string>
using namespace std;

void reverseStr(string& str, int start, int end) {
    if (start >= end) {
        return;
    }
    swap(str[start], str[end]);
    reverseStr(str, start + 1, end - 1);
}

string reverseString(const string& str) {
    string reversedStr = str;  // Create a copy of the original string
    reverseStr(reversedStr, 0, reversedStr.size() - 1);
    return reversedStr;
}

int main() {
    string str = "Hello, World!";
    string reversedStr = reverseString(str);
    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reversedStr << endl;
    return 0;
}
