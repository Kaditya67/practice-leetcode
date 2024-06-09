#include <iostream>
#include <string>

using namespace std;

string intToRoman(int num) {
    const string romanNumerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string result;

    for (int i = 0; i < 13; ++i) {
        cout<<"Num >= values[i]: "<<num<<" >= "<<values[i]<<" = "<<(num>=values[i])<<endl;
        while (num >= values[i]) {
            result += romanNumerals[i];
            cout<<"Result: "<<result<<endl;
            num -= values[i];
            cout<<"Num -= values[i]: "<<num<<endl;
        }

        cout<<endl<<endl;
    }

    return result;
}

int main() {
    int num = 3749;
    cout << intToRoman(num) << endl; // Output: "MMMDCCXLIX"
    return 0;
}
