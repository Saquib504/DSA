#include <iostream>
using namespace std;

typedef unsigned long long ull;
int numDistinct(string s, string t) {
    int m = s.size();
    int n = t.size();
    vector<ull> prev(n+1, 0);
    prev[0] = 1;

    for(int i = 1; i <= m; i++) {
        vector<ull> curr(n+1, 0);
        curr[0] = 1;
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == t[j-1]) {
                curr[j] = prev[j-1] + prev[j];
            } else {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return prev[n];
}


int main() {
    string s, t;
    cout << "Enter s and t : "; cin >> s >> t;

    cout << "Total number of distinct subsequences of s which equals t : " << numDistinct(s, t) << endl;
    return 0;
}