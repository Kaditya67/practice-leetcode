#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;

    // Check if the number is even or odd
    if (num & 1) {
        cout << "Number is ODD" << endl;
    } else {
        cout << "Number is EVEN" << endl;
    }

    // Calculate and print the binary representation
    string binary = "";
    int temp = num;
    if (temp == 0) {
        binary = "0";
    } else {
        while (temp > 0) {
            binary = (temp % 2 == 0 ? "0" : "1") + binary;
            temp /= 2;
        }
    }
    cout << "Binary representation: " << binary << endl;

    // Iterate through each bit using bitwise operations
    for (int i = binary.size(); i > 0; i--) {
        if()
        cout << i << " bit is: " << (num & 1) << endl;
        num = num >> 1; // Always shift by 1
    }

    return 0;
}
