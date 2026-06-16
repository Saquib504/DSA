#include <iostream>
#include <vector>
using namespace std;

string processStr(string s) {
    int n = s.size();
    if(n == 0) return "";
    string res = "";

    for(int i = 0; i < n; i++) {

        //condition-1   -->     If the letter is a lowercase English letter append it to result.
        if(s[i] >= 'a' && s[i] <= 'z') {
            res += s[i];
        }
        //condition-2   -->     '*' removes the last character from result, if it exists.
        else if(s[i] == '*') {
            int resSize = res.size();
            if(!res.empty()) {
                res = res.substr(0,resSize-1);
            }
        }

        //condition-3   -->     '#' duplicates the current result and appends it to itself.
        else if(s[i] == '#') {
            res += res;
        }

        //condition-4   -->     '%' reverses the current result.
        else if(s[i] == '%') {
            reverse(res.begin(), res.end());
        }
    }
    return res;
}


int main() {
    string s;
    cout << "\nInput: ";  cin >> s;
    string ans = processStr(s);

    cout << "\nThe resultant string is : " << ans << endl;

    return 0;
}