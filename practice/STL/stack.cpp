#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<string> s;

    s.push("abc");
    s.push("def");
    s.push("ghi");
    s.push("jkl");

    cout << "Element on the top: " << s.top() << endl;

    s.pop(); // Corrected here

    cout << "Element popped." << endl;
    cout << "Element on the top: " << s.top() << endl;

    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl;

    return 0;
}
