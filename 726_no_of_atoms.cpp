#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());

        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;

                string mul;
                while (i < n && isdigit(formula[i])) {
                    mul.push_back(formula[i]);
                    i++;
                }

                int mulInt = (mul.empty() ? 1 : stoi(mul));

                for (auto& it : curr) {
                    st.top()[it.first] += it.second * mulInt;
                }
            } else {
                string currElement;
                currElement.push_back(formula[i]);
                i++;

                while (i < n && isalpha(formula[i]) && islower(formula[i])) {
                    currElement.push_back(formula[i]);
                    i++;
                }

                string currCount;
                while (i < n && isdigit(formula[i])) {
                    currCount.push_back(formula[i]);
                    i++;
                }

                int currCountInt = (currCount.empty() ? 1 : stoi(currCount));
                st.top()[currElement] += currCountInt;
            }
        }

        map<string, int> sortedMap(st.top().begin(), st.top().end());
        string result;
        for (auto& it : sortedMap) {
            result += it.first;
            if (it.second > 1) {
                result += to_string(it.second);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Test cases
    string formula1 = "H2O";
    string formula2 = "Mg(OH)2";
    string formula3 = "K4(ON(SO3)2)2";

    cout << "Formula: " << formula1 << " => " << solution.countOfAtoms(formula1) << endl;
    cout << "Formula: " << formula2 << " => " << solution.countOfAtoms(formula2) << endl;
    cout << "Formula: " << formula3 << " => " << solution.countOfAtoms(formula3) << endl;

    return 0;
}
