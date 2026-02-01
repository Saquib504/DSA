#include <iostream>
#include <stack>
#include <string>

using namespace std;


int prec(char c) {
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}
string infixToPostfix(string s) {
    // Your code goes here
    stack<char> stk;
    string ans = "";

    for(int i = 0; i < s.length(); i++) {
        char c = s[i];

        //if char is an operand
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')) {
            ans += c;
        }
        // if char is an ( bracket
        else if(c == '(') {
            stk.push('(');
        }
        // if char is a ) bracket
        else if(c == ')') {
            while(stk.top() != '(') {
                ans += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        // else it is an operator
        else {
            while(!stk.empty() && prec(c) <= prec(stk.top())) {
                ans += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }

    while(!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }

    return ans;
}

int main() {
    string exp = "(p+q)*(m-n)";  // Infix expression
    cout << "Infix expression: " << exp << endl;
    exp = infixToPostfix(exp);  // Convert the infix expression to postfix
    cout << "Postfix expression: " << exp << endl;
    return 0;
}