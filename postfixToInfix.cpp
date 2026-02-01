#include <iostream>
#include <stack>
#include <string>
using namespace std;

string postfixToInfix(string postExp) {
    // Your code goes here
    stack<string> stk;


    for(int i = 0; i < postExp.length(); i++) {
        char c = postExp[i];

        if(isalnum(c)) {
            stk.push(string(1,c));
        }
        else {
            string s1 = stk.top(); stk.pop();
            string s2 = stk.top(); stk.pop();

            stk.push('(' + s2 + c + s1 + ')');
        }
    }

    return stk.top();
}


int main() {
    string exp = "abc*+";  // Infix expression
    cout << "Postfix expression: " << exp << endl;
    cout << "Infix expression: " << postfixToInfix(exp) << endl;
    return 0;
}