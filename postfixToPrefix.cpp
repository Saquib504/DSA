#include <iostream>
#include <string>
#include <stack>
using namespace std;

string postfixToPrefix(string postfix) {
    // Your code goes here
    stack<string> stk;

    for(int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if(isalnum(c)) {
            stk.push(string(1,c));
        }

        else {
            string s1 = stk.top();  stk.pop();
            string s2 = stk.top();  stk.pop();

            stk.push(c + s2 +s1);
        } 
    }

    return stk.top();
}

int main() {
    string exp = "ab+cd-*";  // Infix expression
    cout << "Postfix expression: " << exp << endl;
    cout << "Prefix expression: " << postfixToPrefix(exp) << endl;
    return 0;
}