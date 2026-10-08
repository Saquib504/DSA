#include <iostream>
using namespace std;


string removeOuterParentheses(string s) {
    int n = s.size();
    int l = 0, r = 0;
    int cnt = 0;
    string res = "";

    while(r < n) {
        if(s[r] == '(') {
            cnt++;
        }
        else {
            cnt--;
            if(cnt == 0) {
                res += s.substr(l+1, r - l - 1);
                l = r + 1;
            }
        }
        r++;
    }

    return res;
}



int main() {
    string s; cout << "Enter : "; cin >> s;
    cout << "Resultant string is : " << removeOuterParentheses(s) << endl;
    return 0;
}