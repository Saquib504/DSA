#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int n;
string s;
int idx;

set<string> performConcat();
set<string> performUnion();

set<string> getUnit() {
    set<string> result;

    if(s[idx] == '{') {
        idx++;
        result = performUnion();
    } else {
        result = {string(1, s[idx])};
    }
    idx++;
    
    return result;
}

set<string> performConcat() {
    set<string> result = {""};

    while(idx < n && (s[idx] == '{' || isalpha(s[idx]))) {
        set<string> temp = getUnit();
        set<string> concatResult;

        for(const string& left : result) {
            for(const string& right : temp) {
                concatResult.insert(left + right);
            }
        }
        result = concatResult;
    }

    return result;
}

set<string> performUnion() {
    set<string> result;

    while(true) {
        set<string> temp = performConcat();
        result.insert(begin(temp), end(temp));

        if(idx < n && s[idx] == ',') {
            idx++;
        } else {
            break;
        }
    }

    return result;
}

vector<string> braceExpansionII(string expression) {
    n = expression.size();
    s = expression;
    idx = 0;
    set<string> temp =  performUnion();
    vector<string> result(begin(temp), end(temp));

    return result;
}



int main() {
    string expression;
    cout << "Enter the Expression : "; cin >> expression;

    vector<string> ans = braceExpansionII(expression);

    cout << "| ";
    for(auto exp : ans) {
        cout << "\"" <<  exp << "\"" << "  |  ";
    }cout<<endl;

    return 0;
}