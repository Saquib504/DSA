#include <iostream>
using namespace std;

// RECURSION + MEMOIZATION
// int f(int i, int j, string&s1, string&s2, vector<vector<int>> &memo) {
//     if(i < 0) return 0;
//     if(j < 0) return 1;

//     if(memo[i][j] != -1) return memo[i][j];

//     if(s1[i] == s2[j]) {
//         return memo[i][j] = f(i-1, j-1, s1, s2, memo) + f(i-1, j, s1, s2, memo);
//     }
    
//     return memo[i][j] = f(i-1, j, s1, s2, memo);
// }

// TABULATION METHOD
// int distsubsequence(string&s1, string &s2) {
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>>memo(n+1, vector<int>(m+1,0));

//     for(int i = 0; i <= n; i++) {
//         memo[i][0] = 1;
//     }

//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
//             if(s1[i-1] == s2[j-1]) {
//                 memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
//             }
//             else{
//                 memo[i][j] = memo[i-1][j];
//             }
//         }
//     }
//     return memo[n][m];
// }

// SPACE OPTIMIZATION
int distsubsequence(string&s1, string &s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int>prev(m+1, 0);
    prev[0] =1;

    for(int i = 1; i <= n; i++) {
        vector<int>temp(m+1, 0);
        temp[0] = 1;
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                temp[j] = prev[j-1] + prev[j];
            }
            else{
                temp[j] = prev[j];
            }
        }
        prev = temp;
    }
    return prev[m];
}

int main() {
    string s1 = "rabbbit"; //cout << "Enter string A = "; cin >> s1;
    string s2 = "rabbit"; //cout << "Enter string b = "; cin >> s2;

    cout << "The number of distinct subsequences are " << distsubsequence(s1, s2) << endl;

    return 0;
}