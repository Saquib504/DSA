#include <iostream>
#include <stack>
#include <string>
using namespace std;

string prefixToInfix(string prefix) {
    stack<string> s;
    int n = prefix.size();
    int i = n-1;

    // Traverse the prefix expression from right to left
    while(i >= 0) {
        char c = prefix[i];

        // If the character is an operand, push it to the stack
        // if (isalnum(c)) {
        //     s.push(string(1, c));
        // } 
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')) {
            s.push(string(1, c));
        }
        else {
            // Pop two operands from the stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // Form the new infix expression and push back to stack
            s.push("(" + op1 + c + op2 + ")");
        }
        i--;
    }

    // The final element in the stack is the result
    return s.top();
}

int main() {
    string exp = "*+ab-cd";  // Infix expression
    cout << "Prefix expression: " << exp << endl;
    cout << "Infix expression: " << prefixToInfix(exp) << endl;
    return 0;
}