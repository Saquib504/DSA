#include <iostream>
using namespace std;


string supersequence(string&s1, string&s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>>memo(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                memo[i][j] = 1 + memo[i-1][j-1];
            }
            else {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }
    string ans = "";
    int i = n, j = m;

    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            ans = s1[i-1] + ans;
            i--;
            j--;
        }
        else if(memo[i-1][j] > memo[i][j-1]) {
            ans = s1[i-1] + ans;
            i--;
        }
        else {
            ans = s2[j-1] + ans;
            j--;
        }
    }

    while (i > 0)
    {
        ans = s1[i-1] + ans;
        i--;
    }
    while (j > 0)
    {
        ans = s2[j-1] + ans;
        j--;
    }

    return ans;
}

int main() {

    string s1; cout << "Enter String A : ";cin >> s1;
    string s2; cout << "Enter String B : ";cin >> s2;

    cout << "The minimum number of operations to convert string A to B is " << supersequence(s1,s2) << endl;
    return 0;
}