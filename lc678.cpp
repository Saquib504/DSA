#include <iostream>
using namespace std;

bool validParenthesis(string s) {
    int l = 0, h = 0;

    for(char c : s) {
        if(c == '(') {
            l++;
            h++;
        }
        else if(c == ')') {
            l--;
            h--;
        }
        else if(c == '*') {
            l--;
            h++;
        }

        if(h < 0) return false;
        l = max(l, 0);
    }
    return l == 0;
}

int main() {
    cout << endl;
    cout << "LC678: Valid Parenthesis String" << endl;
    string s; cout << "Enter the parenthesis string: ";
    cin >> s;

    cout << "Is the parenthesis string valid: " << (validParenthesis(s) ? "True" : "False") << endl;
    cout << endl;
    return 0;
}