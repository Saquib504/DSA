#include <iostream>
#include <stack>
#include <string>
using namespace std;


int maxDepth(string s) {
    int n = s.size();
    stack<char> stk;

    int depth = 0, depthMax = 0;

    for(auto &ch : s) {
        if(ch == '(') {
            depth++;
            depthMax = max(depth, depthMax);
        } else if(ch == ')') {
            depth--;
        }
    }

    return depthMax;
}

int main() {
    string s;
    cout << "Enter String s : ";cin >> s;

    cout << "The maximum depth is : " << maxDepth(s) << endl;

    return 0;
}