#include <iostream>

using namespace std;

int gcd(int x, int y) {
    cout<<x<<" "<<y<<endl;
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;
    return 0;
}