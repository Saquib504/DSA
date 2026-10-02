#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<string> generateParenthesis(int n) {
    if(n-- == 1) return {"()"};

    vector<string> result;

    auto dfs = [&](auto&self, int o, int c, string s) -> void {
        if(o == 0 || c == 0) {
            result.push_back(s + ")");
            return;
        }

        if(o > 0) {
            self(self, o-1, c, s + "(");
        }

        if(c > 0) {
            self(self, o, c-1, s + ")");
        }
    };

    dfs(dfs, n, n, "(");

    return result;
}



int main() {
    int n; cin >> n;

    vector<string> ans = generateParenthesis(n);

    for(auto & x : ans) {
        cout << x << "\n";
    }
    return 0;
}