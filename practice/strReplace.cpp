#include <iostream>
#include <vector>
using namespace std;

string replaceSpaces(string &str) {
    string result;
    for (char ch : str) {
        if (ch == ' ') {
            result += "@40";
        } else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string str = "Mr John Smith    ";
    cout << replaceSpaces(str) << endl;
    return 0;
}