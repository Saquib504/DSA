#include <iostream>
#include <string>
using namespace std;



    string removeStars(string s) {
        stack<char> stk;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == '*' && !stk.empty()) stk.pop();
            else stk.push(s[i]);
        }

        string ans = "";
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

int main() {
    string s = "leet**cod*e";
    cout << removeStars(s) << endl; // Output: "lecoe"
    return 0;
}