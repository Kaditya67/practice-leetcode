#include <iostream>
#include <stack>
#include <string>
using namespace std;


// Infix:   a+b*(c^d-e)^(f+g*h)-i
// Postfix: abcd^e-fgh*+^*+i-

// Note : If next operand is of greater precedence, just keep pushing to keep it on the top 

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(const string& expr) {
    string result = "";
    stack<char> st;

    for (char ch : expr) {
        if (isalnum(ch)) {
            result += ch; // operand
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // pop '('
        } else if (isOperator(ch)) {
            while (!st.empty() && st.top() != '(' &&
                  (precedence(st.top()) > precedence(ch) ||
                   (precedence(st.top()) == precedence(ch) && !isRightAssociative(ch)))) {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

string postfixToInfix(const string& postfix) {
    stack<string> st;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            // Operand → push as string
            st.push(string(1, ch));
        } else if (isOperator(ch)) {
            if (st.size() < 2) {
                return "Invalid postfix expression!";
            }
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            string infix = "(" + op1 + ch + op2 + ")";
            st.push(infix);
        }
    }

    // Final result should be one full infix expression
    return st.size() == 1 ? st.top() : "Invalid postfix expression!";
}


int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);

    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    return 0;
}
