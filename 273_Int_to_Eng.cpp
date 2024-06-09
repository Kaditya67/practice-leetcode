#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero"; // Handle special case
        
        // All this ones and tens are used to convert numbers into words directly
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        // In tens but only multiple of 10
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        // After tens
        vector<string> scales = {"", "Thousand", "Million", "Billion"};
        
        string result;
        int scale = 0;
        
        while (num > 0) { // Filter all numbers greater than 1000
            if (num % 1000 != 0) { // Process groups of three digits
                string groupWords = convertThreeDigits(num % 1000, ones, tens); // less than 1000 are passed here
                cout<<"groupWords: "<<groupWords<<endl;

                result = groupWords + (scale > 0 ? " " + scales[scale] : "") + (result.empty() ? "" : " ") + result;

                cout<<"result: "<<result<<endl;
            }
            num /= 1000;        
            // 12345/1000 = 12
            scale++;

            cout<<"scale: "<<scale<<endl;

            cout<<endl<<endl;
        }
        
        return result;
    }
    
private:
    string convertThreeDigits(int num, vector<string>& ones, vector<string>& tens) {
        string result;
        
        // Suppose 923
        // First convert 923 / 100 = 9 Hundred      ---> index 9 in ones
        if (num >= 100) {
            result += ones[num / 100] + " Hundred";
            num %= 100;     // Remove the 1st digit
            if (num != 0) result += " ";// Add spaces if numm is not yet zero
        }
        
        // Now convert 23/10=2 --> index 2 in tens
        if (num >= 20) {
            result += tens[num / 10];
            num %= 10;      // Remove the 1st digit
            if (num != 0) result += " ";        // Add space if numm is not yet zero
        }
        
        // 3 --> index 3 in ones
        if (num > 0) {
            result += ones[num];
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // // Test cases
    // cout << "123: " << solution.numberToWords(123) << endl;
    // cout << "12345: " << solution.numberToWords(12345) << endl;
    cout << "1234567: " << solution.numberToWords(1234567) << endl;
    
    return 0;
}
