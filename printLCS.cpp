#include <iostream>
using namespace std;


string findLCS(string&s1, string&s2) {
    int n = s1.size();
    int m  = s2.size();

    vector<vector<int>>memo(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                memo[i][j] = 1 + memo[i-1][j-1];
            }
            else {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }

    int i = n, j = m;
    int len = memo[n][m];
    string ans = "";
    for(int i =0; i < len; i++) ans += '#';

    int index = len-1;

    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            ans[index] = s1[i-1];
            index--;
            i--;j--;
        }
        else if(memo[i-1][j] > memo[i][j-1]){
            i--;
        }
        else j--;
    }
    return ans;
}

int main() {
    string s1 = "abcde";
    string s2 = "bdgek";


    cout << "Th longest common subsequence is : " << findLCS(s1,s2) << endl;
    return 0;
}