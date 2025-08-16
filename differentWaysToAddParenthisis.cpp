#include <iostream>
#include <string>
using namespace std;

vector<int> f(int i, int j, string &s) {
    // Base case: substring is a number
    string sub = s.substr(i, j - i + 1);
    bool isNumber = true;
    for (char c : sub) {
        if (!isdigit(c)) { isNumber = false; break; }
    }
    if (isNumber) return { stoi(sub) };

    vector<int> results;

    // Try all operators as split points
    for (int ind = i+1; ind <= j-1; ind+=2) {
        char c = s[ind];
        if (c == '+' || c == '-' || c == '*') {
            vector<int> left = f(i, ind - 1, s);
            vector<int> right = f(ind + 1, j, s);

            for (int a : left) {
                for (int b : right) {
                    if (c == '+') results.push_back(a + b);
                    else if (c == '-') results.push_back(a - b);
                    else results.push_back(a * b);
                }
            }
        }
    }
    return results;
}

vector<int> diffWaysToCompute(string s) {
    return f(0, s.size() - 1, s);
}

int main() {
    string s = "2*3-4*5";
    vector<int> ans = diffWaysToCompute(s);

    for (int x : ans) cout << x << ", ";
    cout << endl;
    return 0;
}
