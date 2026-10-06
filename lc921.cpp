#include <iostream>
#include <stack>
#include <string>
using namespace std;



// TC -> O(N)
// SC -> O(N)
int minAddToMakeValid(string s) {
    stack<char> stk;

    for(auto& ch : s) {
        if(ch == '(') {
            stk.push(ch);
        } else {
            if(!stk.empty() && stk.top() == '(') {
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
    }

    return stk.size();
}

// TC -> O(N)
// SC -> O(1)
int minAddToMakeValid(string s) {

    int opens = 0, addons = 0;

    for(auto& ch : s) {
        if(ch == '(') {
           opens++;
        } else {
            if(opens > 0) {
                opens++;
            } else {
                addons++;
            }
        }
    }

    return addons + opens;
}


int main() {
    string s; cout << "Enter string : "; cin >> s;

    cout << "Minimum Add to Make Parentheses Valid : " << minAddToMakeValid(s) << endl;
    return 0;
}