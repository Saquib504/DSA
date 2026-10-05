#include <iostream>
using namespace std;


int scoreOfParentheses(string s) {
    int score = 0, depth = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            depth++;
        } else {
            depth--;
            if(s[i-1] == '(') {
                score += (1 << depth);
            }
        }
    }

    return score;
}


int main() {
    string s;
    cout << "Enter : "; cin >> s;
    cout << "Total Score of Parenthesis : " << scoreOfParentheses(s) << endl;
    return 0;
}