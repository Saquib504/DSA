#include <iostream>
using namespace std;


bool isValid(string s) {
    int n = s.size();
    stack<char> stk;

    for(int i = 0; i < n; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk.push(s[i]);
        } 
        else if(stk.empty()) return false;
        else if(s[i] == ')' && !stk.empty() && stk.top() == '(') {
            stk.pop();
        }
        else if(s[i] == ']' && !stk.empty() && stk.top() == '[') {
            stk.pop();
        }
        else if(s[i] == '}' && !stk.empty() && stk.top() == '{') {
            stk.pop();
        }
        else return false;
    }
    return stk.empty() ? true : false;
}

int main() {
    string s;
    cout << "Enter : "; cin >> s;

    return isValid(s);
}