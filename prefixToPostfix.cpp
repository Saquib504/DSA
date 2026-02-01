#include <iostream>
#include <stack>
#include <string>
using namespace std;

string prefixToPostfix(const string& s) {
    // Your code goes here
    stack<string> stk;
    int i = s.length() -1;

    while(i >= 0) {
        char c = s[i];

        if(isalnum((c))) {
            stk.push(string(1,c));
        }
        else {
            string s1 = stk.top();  stk.pop();
            string s2 = stk.top();  stk.pop();

            stk.push(s1 + s2 + c);
        }
        i--;
    }

    return stk.top();
}

int main() {
    string exp = "*+ab-cd";  // Infix expression
    cout << "Prefix expression: " << exp << endl;
    cout << "Postfix expression: " << prefixToPostfix(exp) << endl;
    return 0;
}